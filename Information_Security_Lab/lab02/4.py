from Crypto.Cipher import DES3
from Crypto.Util.Padding import pad, unpad

# Corrected 3DES key (at least two unique parts)
key_hex = "0123456789ABCDEFFEDCBA98765432100123456789ABCDEF"
key = bytes.fromhex(key_hex)

# Adjust key parity (required by DES3)
key = DES3.adjust_key_parity(key)

# Create cipher
cipher = DES3.new(key, DES3.MODE_ECB)

# Message
plaintext = b"Classified Text"
padded = pad(plaintext, DES3.block_size)

# Encrypt
ciphertext = cipher.encrypt(padded)
print("Ciphertext (hex):", ciphertext.hex())

# Decrypt
decrypted = unpad(cipher.decrypt(ciphertext), DES3.block_size)
print("Decrypted message:", decrypted.decode())