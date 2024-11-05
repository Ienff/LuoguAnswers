import sys
from functools import cmp_to_key

input = sys.stdin.read
lines = input().strip().split('\n')
N = int(lines[0])
numbers = list(lines[1].split())

def compare(a, b):
    if a + b > b + a:
        return -1
    elif a + b < b + a:
        return 1
    else:
        return 0

sorted_numbers = sorted(numbers[:N], key=cmp_to_key(compare))

print(''.join(sorted_numbers))
