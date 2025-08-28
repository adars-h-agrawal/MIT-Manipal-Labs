from Crypto.Cipher import DES
from Crypto.Util.Padding import pad, unpad

# Convert key and plaintext to bytes
key = b"A1B2C3D4"  # 8 bytes key
plaintext = b"Confidential Data"

# Pad plaintext to be a multiple of 8
padded_text = pad(plaintext, DES.block_size)

# Create DES cipher in ECB mode
cipher = DES.new(key, DES.MODE_ECB)

# Encrypt
ciphertext = cipher.encrypt(padded_text)
print("Ciphertext (hex):", ciphertext.hex())

# Decrypt
decrypted_padded = cipher.decrypt(ciphertext)

# Unpad to get original plaintext
decrypted = unpad(decrypted_padded, DES.block_size)
print("Decrypted message:", decrypted.decode())