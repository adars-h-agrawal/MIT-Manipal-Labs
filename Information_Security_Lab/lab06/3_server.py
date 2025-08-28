import socket, random
from crypto_lib import diffie_hellman, elgamal_keygen, elgamal_decrypt, schnorr_verify

HOST, PORT = "127.0.0.1", 5001
p, g = 467, 2

# Generate DH values
a = random.randint(2, p-2)
A = pow(g, a, p)

# Generate ElGamal keys
pub, priv = elgamal_keygen(p, g)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    print("Server listening...")

    conn, addr = s.accept()
    with conn:
        print("Connected:", addr)

        # Exchange public values
        B = int(conn.recv(1024).decode())
        conn.send(str(A).encode())

        shared = pow(B, a, p)
        print("Shared secret:", shared)

        # Receive ciphertext
        data = conn.recv(1024).decode().split("|")
        a_val, b_val = int(data[0]), int(data[1])
        msg = elgamal_decrypt((a_val, b_val), priv, pub)
        print("Decrypted message:", msg)



'''

Sample Output

Server listening...
Connected: ('127.0.0.1', 50322)
Shared secret: 362
Decrypted message: 362

'''