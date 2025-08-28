import socket, random
from crypto_lib import diffie_hellman, elgamal_encrypt

HOST, PORT = "127.0.0.1", 5001
p, g = 467, 2

# Generate DH values
b = random.randint(2, p-2)
B = pow(g, b, p)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))

    s.send(str(B).encode())
    A = int(s.recv(1024).decode())

    shared = pow(A, b, p)
    print("Shared secret:", shared)

    # Encrypt message with ElGamal (using shared secret as message for demo)
    pub = (p, g, pow(g, b, p))
    cipher = elgamal_encrypt(shared, pub)

    s.send(f"{cipher[0]}|{cipher[1]}".encode())
    print("Message sent:", cipher)


'''

Sample Output

Shared secret: 362
Message sent: (326, 146)

'''