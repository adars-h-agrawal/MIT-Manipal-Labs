from Crypto.Cipher import AES
import base64
import hashlib

BLOCK_SIZE = 16

def pad(s):  
    return s + (BLOCK_SIZE - len(s) % BLOCK_SIZE) * chr(BLOCK_SIZE - len(s) % BLOCK_SIZE)

def unpad(s):  
    return s[:-ord(s[len(s) - 1:])]

def get_key(secret):
    return hashlib.sha256(secret.encode()).digest()

def encrypt(raw, secret):
    raw = pad(raw)
    key = get_key(secret)
    cipher = AES.new(key, AES.MODE_ECB)
    return base64.b64encode(cipher.encrypt(raw.encode())).decode()

def decrypt(enc, secret):
    key = get_key(secret)
    cipher = AES.new(key, AES.MODE_ECB)
    return unpad(cipher.decrypt(base64.b64decode(enc)).decode())
