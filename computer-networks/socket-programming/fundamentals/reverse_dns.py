
import socket

ip_addresses = ["172.16.5.43", "8.8.8.8"]

for ip_address in ip_addresses:
    try:
        hostname, aliases, addresses = socket.gethostbyaddr(ip_address)
        print(f"IP Address: {ip_address}")
        print(f"Hostname: {hostname}")
        print(f"Aliases: {aliases}\n")
    except socket.herror as error:
        print(f"Lookup failed for {ip_address}: {error}\n")