#!/usr/bin/python3
"""
File finding the minimum number of operation
"""


def minOperations(n):
    nb_of_operations = 0

    if n < 2:
        return 0

    i = 2

    while n > 1:
        while n % i == 0:
            nb_of_operations += i
            n = n // i
        i += 1

    return nb_of_operations
