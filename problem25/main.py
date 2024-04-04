d = {}


def power(n, F):
    """  """
    if n in d:
        return d[n]
    else:
        F1 = power(n // 2, F)
        F2 = power(n - (n // 2), F)
        resF = [
            [
                F1[0][0] * F2[0][0] + F1[0][1] * F2[1][0],
                F1[0][0] * F2[0][1] + F1[0][1] * F2[1][1]
            ],
            [
                F1[1][0] * F2[0][0] + F1[1][1] * F2[1][0],
                F1[1][0] * F2[0][1] + F1[1][1] * F2[1][1]
            ]]
        d[n] = resF
        return resF


def fibonacci(n):
    """  """
    F = [[0, 1], [1, 1]]
    X = [1, 1]
    if n == 1:
        return X[0]
    d[1] = F
    curF = power(n - 1, F)
    return curF[0][0] + curF[0][1]


def solve():
    """  """
    l = 4000
    r = 5000
    while l < r:
        half = (l + r) // 2
        x = len(str(fibonacci(half)))
        if x >= 1000:
            r = half
        else:
            l = half + 1
    return r


if __name__ == "__main__":
    print("Result:", solve())
