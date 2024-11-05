import sys

input = sys.stdin.read
lines = input().strip().split('\n')

i=0
while i < len(lines):
    R = int(lines[i])
    if R == 0:
        break
    Col = lines[i + 1]
    i += 2

    last_col = list(Col)
    last_col_copy = last_col.copy()
    first_col = sorted(last_col)
    length = len(Col)
    grid = [['' for _ in range(length)] for _ in range(length)]
    grid[0] = first_col
    grid[-1] = last_col
    map = [0] * length
    for j in range(length):
        map[j] = last_col_copy.index(first_col[j])
        last_col_copy[map[j]] = ''
    for j in range(1, length-1):
        for jj in range(length):
            grid[j][jj] = grid[j-1][map[jj]]
    for j in range(length):
        print(grid[j][R-1], end='')
    print()