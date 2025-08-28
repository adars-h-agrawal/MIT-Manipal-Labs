from cryptography.hazmat.primitives.asymmetric import dh
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
import time

params=dh.generate_parameters(2,512)
t=time.time(); a=params.generate_private_key(); b=params.generate_private_key()
print("\n--- Diffie-Hellman Demo ---")
print("Keygen time(ms):",(time.time()-t)*1000)

t=time.time()
a_shared=a.exchange(b.public_key()); b_shared=b.exchange(a.public_key())
ak=HKDF(hashes.SHA256(),32,None,b"DH").derive(a_shared)
bk=HKDF(hashes.SHA256(),32,None,b"DH").derive(b_shared)
print("Exchange time(ms):",(time.time()-t)*1000," Shared keys equal?",ak==bk)

'''

Sample Output:

--- Diffie-Hellman Demo ---
Keygen time(ms): 12.50
Exchange time(ms): 1.30  Shared keys equal? True

'''