from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives import hashes,serialization
from cryptography.hazmat.primitives.ciphers.aead import AESGCM; import os

priv = ec.generate_private_key(ec.SECP256R1()); pub = priv.public_key()
msg = b"Secure Transactions"

eph = ec.generate_private_key(ec.SECP256R1())
key = HKDF(hashes.SHA256(),32,None,b"ECIES").derive(eph.exchange(ec.ECDH(),pub))
nonce = os.urandom(12)
ct = AESGCM(key).encrypt(nonce, msg, None)

eph_pub = eph.public_key().public_bytes(serialization.Encoding.X962,serialization.PublicFormat.UncompressedPoint)
eph_pub = ec.EllipticCurvePublicKey.from_encoded_point(ec.SECP256R1(),eph_pub)
key2 = HKDF(hashes.SHA256(),32,None,b"ECIES").derive(priv.exchange(ec.ECDH(),eph_pub))
pt = AESGCM(key2).decrypt(nonce,ct,None)

print("\n--- ECC Demo ---")
print("Ephemeral pub (hex, first 40):", eph_pub.public_bytes(serialization.Encoding.X962,serialization.PublicFormat.UncompressedPoint).hex()[:40]+"...")
print("Ciphertext (hex, first 40):", ct.hex()[:40]+"...")
print("Decrypted message:", pt.decode())

'''

Sample Output:

--- ECC Demo ---
Ephemeral pub (hex, first 40): 04c3f9a2e6a1f83e9d28e49d77d3af49b1a0d5f9...
Ciphertext (hex, first 40): 4a11b9c8d1f29d7a6e5b2c97aef038b4c21b8d4a...
Decrypted message: Secure Transactions

'''
