def clean(text):
    return text.replace(" ", "").upper()

def mod_inv(a, m):
    for x in range(1, m):
        if (a * x) % m == 1:
            return x
    return None

def cipher(text, k1, k2=0, decrypt=False, mode='add'):
    if mode == 'add':
        k = -k1 if decrypt else k1
        return ''.join(chr((ord(c) - 65 + k) % 26 + 65) for c in text)
    elif mode == 'mul':
        k = mod_inv(k1, 26) if decrypt else k1
        if not k: return "No inverse!"
        return ''.join(chr((ord(c) - 65) * k % 26 + 65) for c in text)
    elif mode == 'affine':
        k1 = mod_inv(k1, 26) if decrypt else k1
        if not k1: return "No inverse!"
        return ''.join(chr(((ord(c)-65 - k2) * k1 % 26 + 65) if decrypt else ((ord(c)-65) * k1 + k2) % 26 + 65) for c in text)

msg = clean("I am learning information security")

# a) Additive Cipher
add_enc = cipher(msg, 20, mode='add')
add_dec = cipher(add_enc, 20, mode='add', decrypt=True)

# b) Multiplicative Cipher
mul_enc = cipher(msg, 15, mode='mul')
mul_dec = cipher(mul_enc, 15, mode='mul', decrypt=True)

# c) Affine Cipher
aff_enc = cipher(msg, 15, 20, mode='affine')
aff_dec = cipher(aff_enc, 15, 20, mode='affine', decrypt=True)

print("Original: ", msg)
print("\nAdditive:\n Encrypted:", add_enc, "\n Decrypted:", add_dec)
print("\nMultiplicative:\n Encrypted:", mul_enc, "\n Decrypted:", mul_dec)
print("\nAffine:\n Encrypted:", aff_enc, "\n Decrypted:", aff_dec)