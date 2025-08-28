import random
import math
from utils_sse import encrypt, decrypt   # reuse padding if needed

# Paillier helpers
def egcd(a, b):
    if a == 0:
        return b, 0, 1
    g, y, x = egcd(b % a, a)
    return g, x - (b // a) * y, y

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception("No modular inverse")
    return x % m

def lcm(x, y):
    return abs(x*y) // math.gcd(x, y)

class Paillier:
    def __init__(self, p, q):
        self.n = p * q
        self.g = self.n + 1
        self.lam = lcm(p-1, q-1)
        self.n2 = self.n * self.n
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