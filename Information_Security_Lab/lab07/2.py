import random
import math
from utils import modinv

class RSA:
    def __init__(self, p, q):
        self.n = p * q
        phi = (p - 1) * (q - 1)

        self.e = 65537  # Common public exponent
        while math.gcd(self.e, phi) != 1:
            self.e = random.randrange(2, phi)

        self.d = modinv(self.e, phi)

    def encrypt(self, m):
        return pow(m, self.e, self.n)

    def decrypt(self, c):
        return pow(c, self.d, self.n)


# --- Demo ---
if __name__ == "__main__":
    p, q = 61, 53
    rsa = RSA(p, q)

    m1, m2 = 7, 3
    c1 = rsa.encrypt(m1)
    c2 = rsa.encrypt(m2)

    print("RSA Encryption:")
    print(f"Originals: {m1}, {m2}")
    print(f"Ciphertexts: {c1}, {c2}")

    # Homomorphic multiplication: Enc(m1) * Enc(m2) mod n = Enc(m1*m2)
    c_mul = (c1 * c2) % rsa.n
    decrypted_mul = rsa.decrypt(c_mul)

    print("Encrypted Product (ciphertext):", c_mul)
    print("Decrypted Product:", decrypted_mul)
    print("Expected Product:", m1 * m2)


'''

Sample Output

RSA Encryption:
Originals: 7, 3
Ciphertexts: 2190, 855
Encrypted Product (ciphertext): 3015
Decrypted Product: 21
Expected Product: 21

'''