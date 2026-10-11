import socket

def find_service_name():
    for port in [80, 25]:
        print(
            f"TCP port {port} -> "
            f"{socket.getservbyport(port, 'tcp')}"
        )

    print(
        f"UDP port 53 -> "
        f"{socket.getservbyport(53, 'udp')}"
    )

if __name__ == "__main__":
    find_service_name()