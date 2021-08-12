import matplotlib.pyplot as plt

xs = []
ys = []
zs = []

with open('triples.dat') as f:
    for line in f:
        x, y, z = line.split()
        xs.append(float(x))
        ys.append(float(y))
        zs.append(float(z))

fig = plt.figure()
ax = fig.add_subplot(projection='3d')

ax.scatter(xs, ys, zs)

plt.show()
