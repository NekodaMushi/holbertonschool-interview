#!/usr/bin/python3
"""
script that reads stdin line by line and computes metrics
"""

import sys

status_count = {200: 0, 301: 0, 400: 0, 401: 0, 404: 0, 405: 0, 500: 0}
counter = 0
file_size = 0
correct_format = 9
# line_test = (
#     '78.99.227.220 - [2017-02-05 23:25:51.534767] "GET /projects/260 HTTP/1.1" 401 724'
# )
for line in sys.stdin:
    counter += 1
    part = line.split()
    if len(part) != correct_format:
        continue
    status_code = part[-2].strip()
    file_size += int(part[-1].strip())
    if int(status_code) in status_count:
        status_count[int(status_code)] += 1
    if counter == 10:
        print("File size: {}".format(file_size))
        for code, count in sorted(status_count.items()):
            if count > 0:
                print("{}: {}".format(code, count))
        counter = 0

    print("File size: {}".format(file_size))
    for code, count in sorted(status_count.items()):
        if count > 0:
            print("{}: {}".format(code, count))
    counter = 0
