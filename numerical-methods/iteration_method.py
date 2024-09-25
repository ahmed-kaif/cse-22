import math
def f(x):
    return (1/math.sqrt(x+1))
def Iteration(x0, epsilon, N):
    table = []
    fn = f(x0)
    fnp1 = f(fn)
    i = 1
    table.append([i,fn,fnp1,abs(fnp1-fn)])
    while ((abs(fnp1 - fn) >= epsilon) or (i <= N)):
        i = i+1
        fn = fnp1
        fnp1 = f(fn)
        table.append([i,fn,fnp1,abs(fnp1-fn)])

        if (abs(fnp1 - fn) < epsilon):
            printTable(table)
            return fnp1 # root

    printTable(table)
    return "Failed to converge within the maximum number of iterations"

def printTable(table):
    print("Iter |     x_n |    g(x_n)|  |x_{n+1} - x_n|")
    for row in table:
        print(f"{row[0]:4} | {row[1]:8.5f} | {row[2]:8.5f} | {row[3]:8.5f} |")


if __name__ == "__main__":
    x0 = .5
    tolerance = 0.0001
    N = 50
    xr = Iteration(x0,tolerance,N)
    print(f"The approximate root is: {xr:8.5f}")
