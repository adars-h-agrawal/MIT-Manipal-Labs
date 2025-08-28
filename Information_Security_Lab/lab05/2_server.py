import socket
from hash_function import custom_hash  # Save Q1 code in hash_function.py

HOST = '127.0.0.1'
PORT = 65432

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    print("Server listening on", (HOST, PORT))

    conn, addr = s.accept()
    with conn:
        print(f"Connected by {addr}")
        data = conn.recv(1024).decode()
        print("Received:", data)

        # Compute hash
        server_hash = str(custom_hash(data))
        conn.sendall(server_hash.encode())
        print("Hash sent back to client:", server_hash)


'''

Sample Output

Server listening on ('127.0.0.1', 65432)
Connected by ('127.0.0.1', 53512)
Received: DataIntegrityCheck
Hash sent back to client: 1762057791

'''