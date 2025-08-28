from Crypto.Cipher import AES
from Crypto.Util.Padding import pad

# Correct AES-192 key (24 bytes / 48 hex characters)
key_hex = "FEDCBA9876543210FEDCBA9876543210FEDCBA9876543210"
key = bytes.fromhex(key_hex)

# Message
plaintext = b"Top Secret Data"

# Pad the plaintext to 16 bytes
padded = pad(plaintext, AES.block_size)

# Create AES cipher in ECB mode
cipher = AES.new(key, AES.MODE_ECB)

# Encrypt
ciphertext = cipher.encrypt(padded)

# Show result
print("Ciphertext (hex):", ciphertext.hex())