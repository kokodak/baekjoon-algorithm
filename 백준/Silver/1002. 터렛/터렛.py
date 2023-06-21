import sys

a = int(input())


def turret(x1, y1, r1, x2, y2, r2):
    k = (x1 - x2) ** 2 + (y1 - y2) ** 2
    R = max(r1, r2)
    r = min(r1, r2)

    if x1 == x2 and y1 == y2 and r1 == r2:
        return -1

    elif k == (r1 + r2) ** 2:
        return 1

    elif k == (R - r) ** 2:
        return 1

    elif k > (r1 + r2) ** 2:
        return 0

    elif k < (R - r) ** 2:
        return 0

    else:
        return 2


for i in range(a):
    x1, y1, r1, x2, y2, r2 = map(int, sys.stdin.readline().split())
    if r1 == 0 and r2 == 0:
        if x1 == x2 and y1 == y2:
            print(1)
        else:
            print(0)
    else:
        print(turret(x1, y1, r1, x2, y2, r2))
