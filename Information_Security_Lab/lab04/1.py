from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
import random

# --- RSA Key Management ---
class KeyManager:
    def __init__(self): self.keys={}
    def gen_key(self, sys): 
        k=RSA.generate(2048); self.keys[sys]=(k,k.publickey())
    def get_pub(self,sys): return self.keys[sys][1]
    def revoke(self,sys): self.keys.pop(sys,None)

# --- Diffie-Hellman ---
def dh_key(): p=23; g=5; a=random.randint(1,10); A=pow(g,a,p); return a,A,p,g
def dh_shared(priv, B, p): return pow(B,priv,p)

# --- Secure Communication ---
km=KeyManager()
for s in ["Finance","HR","SupplyChain"]: km.gen_key(s)

msg=b"Confidential Report"
pub=km.get_pub("Finance")
cipher=PKCS1_OAEP.new(pub).encrypt(msg)
plain=PKCS1_OAEP.new(km.keys["Finance"][0]).decrypt(cipher)

# --- DH Example (Finance ↔ HR) ---
a,A,p,g=dh_key(); b,B,_,_=dh_key()
shared1=dh_shared(a,B,p); shared2=dh_shared(b,A,p)

print("Encrypted:",cipher[:20],"...")
print("Decrypted:",plain)
print("Shared Key Match:",shared1==shared2)

'''

Sample Output

Encrypted: b'\x12\x9aD...\x8f' ...
Decrypted: b'Confidential Report'
Shared Key Match: True

'''