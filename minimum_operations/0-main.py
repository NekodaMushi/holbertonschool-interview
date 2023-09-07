#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__("0-minoperations").minOperations

n = 47
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 99
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 14354
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 1243
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 155
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 3
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))
