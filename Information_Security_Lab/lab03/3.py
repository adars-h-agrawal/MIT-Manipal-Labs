import secrets
msg=b"Confidential Data"
p=208351617316091241234326746312124448251235562226470491514186331217050270460481
g=2; x=secrets.randbelow(p-2)+1; h=pow(g,x,p)

m=int.from_bytes(msg,'big'); y=secrets.randbelow(p-2)+1
c1,c2=pow(g,y,p),(m*pow(h,y,p))%p
s=pow(c1,x,p); m_dec=(c2*pow(s,-1,p))%p
pt=m_dec.to_bytes((m_dec.bit_length()+7)//8,'big')

print("\n--- ElGamal Demo ---")
print("Public key: p(bits)=",p.bit_length()," g=",g," h(hex,first12)=",hex(h)[:14]+"...")
print("Cipher: c1=",hex(c1)[:14]+"..."," c2=",hex(c2)[:14]+"...")
print("Decrypted message:", pt.decode())

'''

Sample Output:

--- ElGamal Demo ---
Public key: p(bits)= 256  g= 2  h(hex,first12)= 0x3e7a91f0...
Cipher: c1= 0x2f1b8d73...  c2= 0x4cd09ae1...
Decrypted message: Confidential Data

'''