import socket
import struct
import random


def encode_domain(domain):
    result = b""
    parts = domain.split(".")

    for part in parts:
        result += bytes(len(part))
        result += part.encode()

    result += b"\x00"
    return result


def decode_domain(data, offset):
    labels = []
    original_offset = offset
    jumped = False

    while True:
        if offset >= len(data):
            raise ValueError("Invalid DNS name")

        length = data[offset]

        if length == 0:
            offset += 1
            break

        if (length & 0xC0) == 0xC0:
            if offset + 1 >= len(data):
                raise ValueError("Invalid DNS pointer")

            pointer = ((length & 0x3F) << 8) | data[offset + 1]

            if not jumped:
                original_offset = offset + 2

            jumped = True
            offset = pointer
            continue

        offset += 1

        if offset + length > len(data):
            raise ValueError("Invalid DNS label")

        label = data[offset:offset + length].decode(errors="replace")
        labels.append(label)
        offset += length

    name = ".".join(labels)

    if jumped:
        return name, original_offset

    return name, offset


def build_dns_query(domain):
    transaction_id = random.randint(0, 65535)

    flags = 0x0100

    qdcount = 1
    ancount = 0
    nscount = 0
    arcount = 0

    header = struct.pack(
        "!HHHHHH",
        transaction_id,
        flags,
        qdcount,
        ancount,
        nscount,
        arcount
    )

    question = encode_domain(domain)

    qtype = 1
    qclass = 1

    question += struct.pack("!HH", qtype, qclass)

    return header + question, transaction_id


def get_status(flags):
    rcode = flags & 0x000F

    if rcode == 0:
        return "NOERROR"
    elif rcode == 1:
        return "FORMERR"
    elif rcode == 2:
        return "SERVFAIL"
    elif rcode == 3:
        return "NXDOMAIN"
    elif rcode == 4:
        return "NOTIMP"
    elif rcode == 5:
        return "REFUSED"
    else:
        return "UNKNOWN"


def parse_dns_response(data, transaction_id):

    if len(data) < 12:
        raise ValueError("DNS response is too short")

    response_id, flags, qdcount, ancount, nscount, arcount = struct.unpack(
        "!HHHHHH",
        data[:12]
    )

    print("\n========== DNS RESPONSE ==========")
    print("Transaction ID :", hex(response_id))
    print("Flags :", hex(flags))
    print("Status :", get_status(flags))
    print("Questions :", qdcount)
    print("Answers :", ancount)
    print("Authority :", nscount)
    print("Additional :", arcount)

    if response_id != transaction_id:
        raise ValueError("Transaction ID does not match")

    if not (flags & 0x8000):
        raise ValueError("Packet is not a DNS response")

    if get_status(flags) != "NOERROR":
        print("\nDNS query was unsuccessful.")
        return

    offset = 12

    print("\n========== QUESTION ==========")

    for i in range(qdcount):
        name, offset = decode_domain(data, offset)

        if offset + 4 > len(data):
            raise ValueError("Invalid question section")

        qtype, qclass = struct.unpack(
            "!HH",
            data[offset:offset + 4]
        )

        offset += 4

        if qtype == 1:
            type_name = "A"
        else:
            type_name = str(qtype)

        print("Query Name :", name)
        print("Query Type :", type_name)
        print("Query Class :", qclass)

    print("\n========== ANSWERS ==========")

    found_a_record = False

    for i in range(ancount):

        name, offset = decode_domain(data, offset)

        if offset + 10 > len(data):
            raise ValueError("Invalid answer record")

        rtype, rclass, ttl, rdlength = struct.unpack(
            "!HHIH",
            data[offset:offset + 10]
        )

        offset += 10

        if offset + rdlength > len(data):
            raise ValueError("Invalid resource record")

        rdata = data[offset:offset + rdlength]

        if rtype == 1 and rclass == 1 and rdlength == 4:

            ip_address = socket.inet_ntoa(rdata)

            print("\nAnswer Record", i + 1)
            print("Name :", name)
            print("Type : A")
            print("Class : IN")
            print("IPv4 Address :", ip_address)
            print("TTL :", ttl, "seconds")

            found_a_record = True

        else:

            print("\nAnswer Record", i + 1)
            print("Name :", name)
            print("Type :", rtype)
            print("Class :", rclass)
            print("TTL :", ttl, "seconds")

        offset += rdlength

    if not found_a_record:
        print("\nNo IPv4 A record was found")


def dns_lookup(domain, dns_server):

    packet, transaction_id = build_dns_query(domain)

    sock = socket.socket(
        socket.AF_INET,
        socket.SOCK_DGRAM
    )

    sock.settimeout(5)

    try:

        print("\n========================================")
        print("DNS QUERY")
        print("========================================")
        print("Domain :", domain)
        print("DNS Server :", dns_server)
        print("DNS Port : 53")
        print("Transaction ID :", hex(transaction_id))

        sock.sendto(
            packet,
            (dns_server, 53)
        )

        data, address = sock.recvfrom(512)

        print("Response From :", address[0])
        print("Response Size :", len(data), "bytes")

        parse_dns_response(
            data,
            transaction_id
        )

    except socket.timeout:

        print("\nError: DNS request timed out.")

    except OSError as e:

        print("\nSocket Error:", e)

    except ValueError as e:

        print("\nError:", e)

    finally:

        sock.close()

        print("========================================")


print("========================================")
print(" DNS QUERY RESOLUTION PROGRAM")
print("========================================")

dns_server = input(
    "Enter DNS Server IP: "
).strip()

while True:

    domain = input(
        "\nEnter domain name (or 'exit' to quit): "
    ).strip()

    if domain.lower() == "exit":

        print("\nProgram ended.")
        break

    if domain == "":

        print("Error: Domain name cannot be empty.")
        continue

    if "." not in domain:

        print("Error: Please enter a valid domain name.")
        continue

    dns_lookup(
        domain,
        dns_server
    )