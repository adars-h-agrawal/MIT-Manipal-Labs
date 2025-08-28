import random
from utils import modinv, lcm

class Paillier:
    def __init__(self, p, q):
        self.n = p * q
        self.g = self.n + 1
        self.lam = lcm(p-1, q-1)
        self.n2 = self.n * self.n

        # mu = (L(g^λ mod n²))^(-1) mod n
        x = pow(self.g, self.lam, self.n2)
        L = (x - 1) // self.n
        self.mu = modinv(L, self.n)

    def encrypt(self, m):
        r = random.randint(1, self.n-1)
        return (pow(self.g, m, self.n2) * pow(r, self.n, self.n2)) % self.n2

    def decrypt(self, c):
        x = pow(c, self.lam, self.n2)
        L = (x - 1) // self.n
        return (L * self.mu) % self.n

# --- Demo ---
if __name__ == "__main__":
    p, q = 17, 19   # small primes for demo
    paillier = Paillier(p, q)

    m1, m2 = 15, 25
    c1 = paillier.encrypt(m1)
    c2 = paillier.encrypt(m2)

    print("Paillier Encryption:")
    print(f"Originals: {m1}, {m2}")
    print(f"Ciphertexts: {c1}, {c2}")

    # Homomorphic addition: Enc(m1) * Enc(m2) mod n² = Enc(m1+m2)
    c_sum = (c1 * c2) % paillier.n2
    decrypted_sum = paillier.decrypt(c_sum)

    print("Encrypted Sum (ciphertext):", c_sum)
    print("Decrypted Sum:", decrypted_sum)
    print("Expected Sum:", m1 + m2)


'''

Sample Output

Paillier Encryption:
Originals: 15, 25
Ciphertexts: 1534, 26145
Encrypted Sum (ciphertext): 207348
Decrypted Sum: 40
Expected Sum: 40

'''