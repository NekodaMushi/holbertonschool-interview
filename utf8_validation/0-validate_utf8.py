#!/usr/bin/env python3

"""Check UTF 8 Validitity"""


def validUTF8(data):
    for num in data:
        if not (0 < num <= 255):
            return False
