from random import uniform as uni
from math import pi


def get_cordinates():
    return (uni(0, 1), uni(0, 1))


(x, y) = get_cordinates()
inside = 0
outside = 0

for i in range(100000000000000):
    (x, y) = get_cordinates()
    if (x * x + y * y > 1):
        outside = outside + 1
    else:
        inside = inside + 1

ans = 4 * inside / (outside + inside)
print(ans)