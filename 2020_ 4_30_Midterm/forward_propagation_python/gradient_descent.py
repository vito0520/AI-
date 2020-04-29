import numpy as np

def w():
    return np.random.randn(2, 3)

def predict(x):
    return np.dot(x,w())

def sofmax(a):
    exp_a = np.exp(a)
    sum_exp_a = np.sum(exp_a)
    y = exp_a/sum_exp_a

    return y

def corss_entorpy_error(y,t):
    if y.ndim ==1:
        t = t.reshape(1,t.size)
        y = y.reshape(1,y.size)

    batch_size = y.shape[0]
    return -np.sum(np.log(y[np.arange(batch_size),t] +1e-7))/batch_size

def loss(x,t):
    z = predict(x)
    y = sofmax(z)
    loss = corss_entorpy_error(y,t)
    return loss


def numerical_gradient(f, x):
    h = 1e-4
    grad = np.zeros_like(x)

    it = np.nditer(x, flags=['multi_index'], op_flags=['readwrite'])
    while not it.finished:
        idx = it.multi_index
        tmp_val = x[idx]
        x[idx] = tmp_val + h
        fxh1 = f(x)

        x[idx] = tmp_val - h
        fxh2 = f(x)
        grad[idx] = (fxh1 - fxh2) / (2 * h)

        x[idx] = tmp_val
        it.iternext()

    return grad



def gradient_descent(f, init_x, lr=0.01, step_num=100):
    x = init_x

    for i in range(step_num):
        grad = numerical_gradient(f, x)
        x -= lr * grad

    return x


def main():
    x = np.array([0.6,0.9])
    a = predict(x)

    t = np.array([0,0,1])
    n = loss(x,t)
    f = lambda w: loss(x, t)
    dW = numerical_gradient(f, w())
    print(dW)

main()