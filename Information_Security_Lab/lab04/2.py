import random, time
from Crypto.Util import number

# --- Rabin Key Generation (Fast Prime Gen) ---
def rabin_keygen(bits=512):
    def prime4():
        while True:
            p = number.getPrime(bits)
            if p % 4 == 3:
                return p
    p, q = prime4(), prime4()
    n = p * q
    return (n,), (p, q)

# --- Key Manager ---
class RabinKeyManager:
    def __init__(self): self.db = {}; self.logs = []
    def gen(self, hosp):
        pub, priv = rabin_keygen()
        self.db[hosp] = (pub, priv)
        self.logs.append((time.time(), f"Generated {hosp}"))
    def get(self, hosp): return self.db[hosp][0]
    def revoke(self, hosp):
        self.db.pop(hosp, None)
        self.logs.append((time.time(), f"Revoked {hosp}"))
    def renew(self, hosp):
        self.gen(hosp)
        self.logs.append((time.time(), f"Renewed {hosp}"))

# --- Usage ---
km = RabinKeyManager()
km.gen("Hospital_A")
km.gen("Clinic_B")
print("Hospital_A public key:", km.get("Hospital_A"))
km.renew("Clinic_B")
km.revoke("Hospital_A")
print("Logs:", km.logs)


'''

Sample Output


Hospital_A public key: (179294710229992... ,)
Logs: [(..., 'Generated Hospital_A'),
       (..., 'Generated Clinic_B'),
       (..., 'Renewed Clinic_B'),
       (..., 'Revoked Hospital_A')]

'''
