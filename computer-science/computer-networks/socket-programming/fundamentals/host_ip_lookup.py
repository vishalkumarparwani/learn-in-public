
import socket

hostnames = ["www.google.com", "www.facebook.com"]

for hostname in hostnames:
    try:
        ip_address = socket.gethostbyname(hostname)
        print(f"Hostname: {hostname}")
        print(f"IP Address: {ip_address}\n")
    except socket.gaierror as error:
        print(f"Could not resolve {hostname}: {error}")