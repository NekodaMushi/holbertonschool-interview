#!/usr/bin/python3
"""
script that reads stdin line by line and computes metrics
"""

import sys

status_count = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
counter = 0
file_size = 0
correct_format = 9
# your_list = [
#     '68.249.9.20 - [2017-02-05 23:31:22.452556] "GET /projects/260 HTTP/1.1" 200 711',
#     "Hello",
#     '99.196.100.39 - [2017-02-05 23:31:22.954433] "GET /projects/260 HTTP/1.1" 401 658',
#     '128.230.61.246 - [2017-02-05 23:31:23.258076] "GET /projects/260 HTTP/1.1" Hello 292',
#     '116.82.223.35 - [2017-02-05 23:31:24.112360] "GET /projects/260 HTTP/1.1" 301 842',
#     'Holberton - [2017-02-05 23:31:25.003550] "GET /projects/260 HTTP/1.1" 400 12',
#     '7.179.133.121 - [2017-02-05 23:31:25.003550] "GET /projects/260 HTTP/1.1" 400 12',
#     '188.213.11.218-[2017-02-05 23:31:21.690755] "GET /projects/260 HTTP/1.1" 401 1000',
#     '128.230.61.246 - [2017-02-05 23:31:23.258076] "GET /projects/260 HTTP/1.1" 301 292',
# ]

for line in sys.stdin:
    counter += 1
    part = line.split()
    if len(part) != correct_format:
        continue
    # if not isinstance(part[0], (int, float)):
    #     continue
    try:
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
    except:
        ValueError

print("File size: {}".format(file_size))
for code, count in sorted(status_count.items()):
    if count > 0:
        print("{}: {}".format(code, count))
counter = 0
