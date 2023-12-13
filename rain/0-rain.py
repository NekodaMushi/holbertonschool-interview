#!/usr/bin/python3

walls = [3, 0, 2, 1]
walls2 = [3, 1, 1, 1, 1, 0, 2, 1, 1, 1, 2]


def rain(walls):
    last_wall = []
    water_retained = 0

    for i, height in enumerate(walls):
        while last_wall and walls[last_wall[-1]] <= height:
            top = last_wall.pop()
            if not last_wall:
                break
            distance = i - last_wall[-1] - 1

            left_wall = walls[last_wall[-1]]
            right_wall = height
            water_height = min(left_wall, right_wall)

            water_retained += distance * water_height

        last_wall.append(i)
    return water_retained
