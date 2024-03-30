from scipy.optimize import fsolve
import numpy as np
import sys
from sympy import *
import random


# def f_2_2(x):
#     p0 = x[0]
#     p1 = x[1]
#     res = [
#         0.5 * p0 * p0 + 0.5 * p1 * p1 * p1 - p0,
#         0.5 * p0 * p1 + 0.5 - p1
#     ]
#     return res


def get_r(idx, r_lst):
    """
    get r_lst[idx], r[i] = (r[i-1] ^ 2) % 10007
    """
    sz = len(r_lst)
    if idx + 1 > sz:
        for i in range(sz, idx + 1):
            cur_r = r_lst[i - 1]
            next_r = (cur_r * cur_r) % 10007
            r_lst.append(next_r)
    return r_lst[idx]


def solve(k, m):
    """
    """
    r = [306]

    i = 0

    def f(x):
        def fi(x, i):
            # print(x)
            q_times = [0 for _ in range(5)]
            for j in range(m):
                cur_q = get_r(i * m + j, r) % 5
                q_times[cur_q] += 1
            res = 0.0
            # q = 0
            res += q_times[0] / m
            # q = 1
            res += q_times[1] / m * x[i] * x[i]
            # q = 2
            res += q_times[2] / m * x[(2 * i) % k]
            # q = 3
            res += q_times[3] / m * x[(i * i + 1) % k] ** 3
            # q = 4
            res += q_times[4] / m * x[i] * x[(i + 1) % k]
            return res
        return [fi(x, i) - x[i] for i in range(k)]

    root = fsolve(f, [0 for _ in range(k)], maxfev=100000)

    return root[0]


def solve_sym(k, m):
    """
    """
    print("enter solve_sym")
    r = [306]
    i = 0
    x = [var('p%s' % i) for i in range(k)]
    def fi(i):
        q_times = [0 for _ in range(5)]
        for j in range(m):
            cur_q = get_r(i * m + j, r) % 5
            q_times[cur_q] += 1
        res = 0.0
        # q = 0
        res += q_times[0] / m
        # q = 1
        res += q_times[1] / m * x[i] * x[i]
        # q = 2
        res += q_times[2] / m * x[(2 * i) % k]
        # q = 3
        res += q_times[3] / m * x[(i * i + 1) % k] * x[(i * i + 1) % k] * x[(i * i + 1) % k]
        # q = 4
        res += q_times[4] / m * x[i] * x[(i + 1) % k]
        return res
    exprs = [fi(i) - x[i] for i in range(k)]

    def f(xx):
        for i in range(len(xx)):
            x[i] = xx[i]
        print(x)
        print(exprs)
        print(exprs[0])
        return exprs
    root = fsolve(f, [random.random() for _ in range(k)])
    print(exprs)


if __name__ == "__main__":
    if len(sys.argv) < 3:
        print(f"usage: {sys.argv[0]} k m")
        exit(-1)

    k = int(sys.argv[1])
    m = int(sys.argv[2])
    print(solve(k, m))
