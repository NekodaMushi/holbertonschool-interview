#!/usr/bin/python3

"""Check UTF 8 Validitity"""
import codecs


def validUTF8(data):
    # keep 8 least significant bits of each integer
    byte = bytes([num & 0xFF for num in data])

    try:
        valid = codecs.decode(byte, "utf-8")
    except UnicodeDecodeError:
        return False
    else:
        return True
