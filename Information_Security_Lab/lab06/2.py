import random

def modexp(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

def diffie_hellman(p, g):
    a = random.randint(2, p-2)
    b = random.randint(2, p-2)

    A = modexp(g, a, p)
    B = modexp(g, b, p)

    shared1 = modexp(B, a, p)
    shared2 = modexp(A, b, p)

    return A, B, shared1, shared2

# Example Run
if __name__ == "__main__":
    p, g = 467, 2
    A, B, s1, s2 = diffie_hellman(p, g)
    print("\nDiffie-Hellman:")
    print("Alice sends:", A, "Bob sends:", B)
    print("Shared secret (Alice):", s1, "Shared secret (Bob):", s2)


'''

Sample Output

Diffie-Hellman:
Alice sends: 145 Bob sends: 120
Shared secret (Alice): 296 Shared secret (Bob): 296

'''