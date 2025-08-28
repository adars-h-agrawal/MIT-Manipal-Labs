import socket
from hash_function import custom_hash

HOST = '127.0.0.1'
PORT = 65432

message = "DataIntegrityCheck"

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(message.encode())

    server_hash = s.recv(1024).decode()
    client_hash = str(custom_hash(message))

    print("Message sent:", message)
    print("Hash from server:", server_hash)
    print("Locally computed hash:", client_hash)

    if server_hash == client_hash:
        print("✅ Data integrity verified!")
    else:
        print("❌ Data corruption detected!")


'''

Sample Output

Message sent: DataIntegrityCheck
Hash from server: 1762057791
Locally computed hash: 1762057791
✅ Data integrity verified!

'''