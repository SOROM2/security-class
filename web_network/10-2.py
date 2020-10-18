#!/usr/bin/env python

import sys
from pcapfile import savefile
from pcapfile.protocols.transport import tcp

if len(sys.argv) != 2:
    print(f"Usage:\n\t{sys.argv[0]} <file.pcap>")
    exit(1)

f = open(sys.argv[1], "rb")

# open and parse capfile
capfile = savefile.load_savefile(f)

tcp_packets = []

# store packets as tcp
for packet in capfile.packets:
    tcp_packets.append(tcp.TCP(packet.raw()))

syn_count = 0
ack_count = 0

# count syn and ack packets
for pkt in tcp_packets:
    if pkt.syn:
        syn_count += 1
    elif pkt.ack:
        ack_count += 1

print (f"syn count: {syn_count}\nack count: {ack_count}")

