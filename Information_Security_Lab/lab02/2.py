from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad

# AES-128 requires a 16-byte key (128 bits)
# We'll truncate or use the first 16 bytes of the provided key
key = bytes.fromhex("0123456789ABCDEF0123456789ABCDEF")[:16]

# The plaintext message
plaintext = b"Sensitive Information"

# Pad the plaintext to be a multiple of 16 bytes
padded_plaintext = pad(plaintext, AES.block_size)

# Create AES cipher in ECB mode
cipher = AES.new(key, AES.MODE_ECB)

# Encrypt the padded plaintext
ciphertext = cipher.encrypt(padded_plaintext)
print("Ciphertext (hex):", ciphertext.hex())

# Decrypt the ciphertext
decrypted_padded = cipher.decrypt(ciphertext)
decrypted = unpad(decrypted_padded, AES.block_size)
print("Decrypted message:", decrypted.decode())