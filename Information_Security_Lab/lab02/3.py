import time
from Crypto.Cipher import DES, AES
from Crypto.Util.Padding import pad, unpad
from Crypto.Random import get_random_bytes

# Message
message = b"Performance Testing of Encryption Algorithms"

# DES Setup (key = 8 bytes)
des_key = get_random_bytes(8)
des_cipher = DES.new(des_key, DES.MODE_ECB)
padded_message_des = pad(message, DES.block_size)

# AES-256 Setup (key = 32 bytes)
aes_key = get_random_bytes(32)
aes_cipher = AES.new(aes_key, AES.MODE_ECB)
padded_message_aes = pad(message, AES.block_size)

# DES Encryption Timing
start_des_enc = time.time()
des_encrypted = des_cipher.encrypt(padded_message_des)
end_des_enc = time.time()

# DES Decryption Timing
start_des_dec = time.time()
des_decrypted = unpad(des_cipher.decrypt(des_encrypted), DES.block_size)
end_des_dec = time.time()

# AES-256 Encryption Timing
start_aes_enc = time.time()
aes_encrypted = aes_cipher.encrypt(padded_message_aes)
end_aes_enc = time.time()

# AES-256 Decryption Timing
start_aes_dec = time.time()
aes_decrypted = unpad(aes_cipher.decrypt(aes_encrypted), AES.block_size)
end_aes_dec = time.time()

# Output results
print("DES Encryption Time:    {:.8f} seconds".format(end_des_enc - start_des_enc))
print("DES Decryption Time:    {:.8f} seconds".format(end_des_dec - start_des_dec))
print("AES-256 Encryption Time:{:.8f} seconds".format(end_aes_enc - start_aes_enc))
print("AES-256 Decryption Time:{:.8f} seconds".format(end_aes_dec - start_aes_dec))