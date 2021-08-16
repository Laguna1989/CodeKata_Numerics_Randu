import pytest
from randu import Randu
import matplotlib.pyplot as plt

def test_last_decimal_digit():
    N = 5000
    values = []
    r = Randu()
    for i in range(0, N+1):
        value = r.get() % 10

        values.append(value)
        r.next()

    #plt.hist(values)

def test_last_hex_digit():
    N = 5000
    values = []
    r = Randu()
    for i in range(0, N+1):
        value = r.get() % 0x10

        values.append(chr(value))
        r.next()

    plt.hist(values)
