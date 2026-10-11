import socket
import time

target = "127.0.0.1"

print(f"Starting scan on {target}")
start_time = time.time()

for port in range(1, 1025):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.settimeout(0.2)
        result = sock.connect_ex((target, port))

        if result == 0:
            print(f"Port {port} OPEN")

print(f"Time taken: {time.time() - start_time:.2f} seconds")