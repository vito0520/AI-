import numpy as np

def NOR(x1, x2):
    x = np.array([x1, x2])
    w = np.array([0.5, 0.5])
    b = -0.2
    tmp = np.sum(w * x) + b
    if tmp <= 0:
        return 1
    else:
        return 0

def main():
    for xs in [(0, 0), (1, 0), (0, 1), (1, 1)]:
        y = NOR(xs[0], xs[1])
        print(str(xs) + " -> " + str(y))
main()