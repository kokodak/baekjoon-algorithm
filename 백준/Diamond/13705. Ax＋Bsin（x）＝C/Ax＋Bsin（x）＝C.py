from decimal import *

pi = Decimal('3.1415926535897932384626433832795028841971')


def sin(x):
    x = x % (2 * pi)
    getcontext().prec += 2
    i, lasts, s, fact, num, sign = 1, 0, x, 1, x, 1
    while s != lasts:
        lasts = s
        i += 2
        fact *= i * (i - 1)
        num *= x * x
        sign *= -1
        s += num / fact * sign
    getcontext().prec -= 2
    return +s


a, b, c = map(Decimal, map(int, input().split()))
lo = Decimal('0')
hi = Decimal('100000')
cnt = 1000

while cnt > 0:
    mid = (lo + hi) / 2
    fx = a * mid + b * sin(mid)
    if fx > c:
        hi = mid
    elif fx < c:
        lo = mid
    cnt -= 1

print(f"{mid:.6f}")
