def modinv(a, m=26):
    # Modular inverse via Extended Euclidean algorithm
    for x in range(1, m):
        if (a * x) % m == 1:
            return x
    return None

def affine_decrypt(ciphertext, a, b):
    a_inv = modinv(a)
    plaintext = ''
    for c in ciphertext:
        if c.isalpha():
            y = ord(c.upper()) - ord('A')
            x = (a_inv * (y - b)) % 26
            plaintext += chr(x + ord('a'))  # lowercase output
        else:
            plaintext += c
    return plaintext

ciphertext = "XPALASXYFGFUKPXUSOGEUTKCDGEXANMGNVS"
a, b = 5, 6

decrypted = affine_decrypt(ciphertext, a, b)
print("Decrypted message:\n", decrypted)