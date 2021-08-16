class Randu:
    vMax = 2 ** 31

    def __init__(self):
        self.v = 1

    def get(self):
        return self.v

    def next(self):
        self.v = (65539 * self.v) % Randu.vMax