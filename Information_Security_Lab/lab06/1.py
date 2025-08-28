import random
from hashlib import sha256

# Utility: modular exponentiation
def modexp(base, exp, mod):
    return pow(base, exp, mod)

# Utility: Extended GCD
def egcd(a, b):
    if a == 0:
        return b, 0, 1
    g, y, x = egcd(b % a, a)
    return g, x - (b // a) * y, y

# Utility: Modular inverse
def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception("No modular inverse")
    return x % m


# --- ElGamal KeyGen, Encrypt, Decrypt ---
def elgamal_keygen(p, g):
    x = random.randint(2, p - 2)   # Private key
    y = modexp(g, x, p)            # Public key
    return (p, g, y), x

def elgamal_encrypt(msg, pubkey):
    p, g, y = pubkey
    k = random.randint(2, p - 2)
    a = modexp(g, k, p)
    b = (msg * modexp(y, k, p)) % p
    return (a, b)

def elgamal_decrypt(cipher, privkey, pubkey):
    p, g, y = pubkey
    a, b = cipher
    s = modexp(a, privkey, p)
    s_inv = modinv(s, p)
    return (b * s_inv) % p


# --- Schnorr Signature ---
def schnorr_sign(msg, privkey, p, q, g):
    k = random.randint(1, q-1)
    r = modexp(g, k, p)
    e = int(sha256((str(r)+msg).encode()).hexdigest(), 16) % q
    s = (k + privkey*e) % q
    return (r, s)

def schnorr_verify(msg, sig, pubkey, p, q, g):
    r, s = sig
    e = int(sha256((str(r)+msg).encode()).hexdigest(), 16) % q
    v = (modexp(g, s, p) * modinv(modexp(pubkey, e, p), p)) % p
    return v == r


if __name__ == "__main__":
    # small prime for demo
    p, g, q = 467, 2, 233  

    # ElGamal
    pub, priv = elgamal_keygen(p, g)
    message = 123
    cipher = elgamal_encrypt(message, pub)
    decrypted = elgamal_decrypt(cipher, priv, pub)
    print("ElGamal:")
    print("Original:", message, "Cipher:", cipher, "Decrypted:", decrypted)

    # Schnorr
    sig = schnorr_sign("Hello", priv, p, q, g)
    print("\nSchnorr Signature:", sig)
    print("Verification:", schnorr_verify("Hello", sig, pub[2], p, q, g))


'''

Sample Output

ElGamal:
Original: 123 Cipher: (326, 146) Decrypted: 123

Schnorr Signature: (134, 78)
Verification: True

'''