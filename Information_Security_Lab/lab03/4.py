import os,time
from cryptography.hazmat.primitives.asymmetric import rsa,ec,padding
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives import hashes,serialization
from cryptography.hazmat.primitives.ciphers.aead import AESGCM

t=time.time(); rpriv=rsa.generate_private_key(65537,2048); rpub=rpriv.public_key()
rsa_time=(time.time()-t)*1000
t=time.time(); epriv=ec.generate_private_key(ec.SECP256R1()); epub=epriv.public_key()
ecc_time=(time.time()-t)*1000
print("\n--- File Transfer KeyGen ---")
print(f"RSA-2048 keygen: {rsa_time:.2f} ms")
print(f"ECC-P256 keygen: {ecc_time:.2f} ms")

data=os.urandom(1024*1024) # 1 MB

# RSA Hybrid
sk,nonce=os.urandom(32),os.urandom(12)
t=time.time()
ct=AESGCM(sk).encrypt(nonce,data,None)
wrap=rpub.encrypt(sk,padding.OAEP(mgf=padding.MGF1(hashes.SHA256()),algorithm=hashes.SHA256(),label=None))
dec=AESGCM(rpriv.decrypt(wrap,padding.OAEP(mgf=padding.MGF1(hashes.SHA256()),algorithm=hashes.SHA256(),label=None))).decrypt(nonce,ct,None)
print("\nRSA: ok?",dec==data," time(ms):",(time.time()-t)*1000)

# ECC Hybrid
eph=ec.generate_private_key(ec.SECP256R1())
k=HKDF(hashes.SHA256(),32,None,b"ECIES").derive(eph.exchange(ec.ECDH(),epub))
nonce=os.urandom(12)
t=time.time()
ct=AESGCM(k).encrypt(nonce,data,None)
eph_pub=ec.EllipticCurvePublicKey.from_encoded_point(ec.SECP256R1(),
    eph.public_key().public_bytes(serialization.Encoding.X962,serialization.PublicFormat.UncompressedPoint))
k2=HKDF(hashes.SHA256(),32,None,b"ECIES").derive(epriv.exchange(ec.ECDH(),eph_pub))
dec=AESGCM(k2).decrypt(nonce,ct,None)
print("ECC: ok?",dec==data," time(ms):",(time.time()-t)*1000)

'''

Sample Output:

--- File Transfer KeyGen ---
RSA-2048 keygen: 55.20 ms
ECC-P256 keygen: 2.15 ms

RSA: ok? True  time(ms): 180.30
ECC: ok? True  time(ms): 92.45

'''