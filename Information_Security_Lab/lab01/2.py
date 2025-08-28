def shift(ch, k, e=True):
    return chr((ord(ch) - 97 + (k if e else -k)) % 26 + 97)

def clean(t):
    return t.replace(" ", "").lower()

def vigenere(text, key, encrypt=True):
    t = clean(text)
    k = (key * ((len(t) // len(key)) + 1))[:len(t)].lower()
    return ''.join(shift(c, ord(k[i]) - 97, encrypt) for i, c in enumerate(t))

def autokey(text, key, encrypt=True):
    t = clean(text)
    res = ''
    ks = [key] if isinstance(key, int) else [ord(key[0]) - 97]
    
    for i, c in enumerate(t):
        s = ks[i]
        res += shift(c, s, encrypt)
        if encrypt:
            ks.append(ord(res[-1]) - 97)
        else:
            ks.append(ord(c) - 97)

    return res

msg = "the house is being sold tonight"

# Vigenère
v_enc = vigenere(msg, "dollars", True)
v_dec = vigenere(v_enc, "dollars", False)
print("Vigenère Encrypted:", v_enc)
print("Vigenère Decrypted:", v_dec)

# Autokey
a_enc = autokey(msg, 7, True)
a_dec = autokey(a_enc, 7, False)
print("Autokey Encrypted:", a_enc)
print("Autokey Decrypted:", a_dec)