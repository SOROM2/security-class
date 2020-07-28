#!/usr/bin/env python

import sys
from Crypto.Cipher import AES

if len(sys.argv) != 4:
    print (f"Usage:\n{sys.argv[0]} <ciphertext file> <iv file> <key file>")
    sys.exit(1)

cipher_text = ""
with open(sys.argv[1]) as f:
    cipher_text = bytes.fromhex(f.read())

iv = ""
with open(sys.argv[2]) as f:
    iv = bytes.fromhex(f.read())

key = ""
with open(sys.argv[3]) as f:
    key = bytes.fromhex(f.read())

cipher = AES.new(key, AES.MODE_CBC, iv)
plain_text = cipher.decrypt(cipher_text).strip()

print (plain_text)
