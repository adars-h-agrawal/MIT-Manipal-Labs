from cryptography.hazmat.primitives.asymmetric import rsa, padding
from cryptography.hazmat.primitives import hashes

priv = rsa.generate_private_key(65537, 2048); pub = priv.public_key()
msg = b"Asymmetric Encryption"

ct = pub.encrypt(msg, padding.OAEP(mgf=padding.MGF1(hashes.SHA256()),algorithm=hashes.SHA256(),label=None))
pt = priv.decrypt(ct, padding.OAEP(mgf=padding.MGF1(hashes.SHA256()),algorithm=hashes.SHA256(),label=None))

print("\n--- RSA Demo ---")
print("Ciphertext (hex, first 60):", ct.hex()[:60]+"...")
print("Decrypted message:", pt.decode())

'''

Sample Output:

--- RSA Demo ---
Ciphertext (hex, first 60): 5d8b2a1f98eaf7c0b4c12e37a17d1e5d4e89b37c5e6f3d92e9c...
Decrypted message: Asymmetric Encryption

'''