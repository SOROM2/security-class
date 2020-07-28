#!/usr/bin/env python

import sys
from Crypto.Cipher import AES
from textblob import TextBlob

if len(sys.argv) != 2:
    print (f"Usage:\n{sys.argv[0]} <weak ciphertext file>")
    sys.exit(1)

cipher_text = ""
with open(sys.argv[1]) as f:
    cipher_text = bytes.fromhex(f.read())

i = 0
key = "0"
iv = bytes.fromhex(f"{i:0x}".rjust(32, '0'))
while i <= 0xFF:
    key = bytes.fromhex(f"{i:0x}".rjust(64, '0'))
    i += 1
    cipher = AES.new(key, AES.MODE_CBC, iv)
    plain_text = cipher.decrypt(cipher_text).strip().decode("cp437")
    if plain_text.isprintable():
        print(f"Potential key found!: {key}")
        print(f"Decrypted message with key: {plain_text}")
        print(f"Message in hex: {plain_text.encode('utf-8').hex()}")
    else:
        print(f"{i:0x}", end='\r\t\r')


