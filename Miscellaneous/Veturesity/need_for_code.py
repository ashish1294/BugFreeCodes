def frm(x, b):
    """
    Converts given number x, from base 10 to base b

    x -- the number in base 10
    b -- base to convert
    """
    assert(x >= 0)
    assert(1< b < 37)
    r = ''
    import string
    while x > 0:
        r = string.printable[x % b] + r
        x //= b
    return r

import sys
x = int(sys.stdin.readline())
b = int(sys.stdin.readline())
print frm(x, b).upper()
