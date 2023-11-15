#!/usr/bin/python3
"""The N queens puzzle"""
import sys


def nqueens(N):
    """Solve the N queens problem with backtracking."""

    def solve_queens(row, queens):
        """Place queens using backtracking."""
        if row == N:
            print([[i, col] for i, col in enumerate(queens)])
            return

        for col in range(N):
            if all(
                col != q and row - i != col - q and row - i != q - col
                for i, q in enumerate(queens)
            ):
                solve_queens(row + 1, queens + [col])

    solve_queens(0, [])


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)
    nqueens(N)
