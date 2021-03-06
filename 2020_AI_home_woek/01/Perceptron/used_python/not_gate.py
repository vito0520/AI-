import numpy as np

def NOT(x1, x2):
    x = np.array([x1, x2])
    w = np.array([0.5, 0.5])
    tmp = np.sum(w * x)
    if tmp <= 0:
        return 1
    else:
        return 0

def main():
    for xs in [(0, 0), (1, 0), (0, 1), (1, 1)]:
        y = NOT(xs[0], xs[1])
        print(str(xs) + " -> " + str(y))
main()