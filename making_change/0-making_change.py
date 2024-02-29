#!/usr/bin/python3

"""
Something written
"""


def makeChange(coins, total):
    """
    Minimum number of coins to make up total
    :param coins: list of coin values
    :param total: total amount to make up
    :return: minimum number of coins needed or -1 if not possible
    """
    if total <= 0:
        return 0

    min_coins_list = [float("inf")] * (total + 1)
    min_coins_list[0] = 0

    for i in range(1, total + 1):
        for coin in coins:
            if coin <= i:
                min_coins_list[i] = min(min_coins_list[i], min_coins_list[i - coin] + 1)

    if min_coins_list[total] == float("inf"):
        return -1

    return min_coins_list[total]
