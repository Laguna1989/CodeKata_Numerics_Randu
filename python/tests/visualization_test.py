import pytest
import matplotlib.pyplot as plt

from randu import Randu


def test_visualization():
    r = Randu()
    xs = []
    ys = []
    zs = []
    for i in range(0, 1001):
        xs.append(r.get())
        r.next()
        ys.append(r.get())
        r.next()
        zs.append(r.get())
        r.next()
    fig = plt.figure()
    ax = fig.add_subplot(projection='3d')

    ax.scatter(xs, ys, zs)

    plt.show()
