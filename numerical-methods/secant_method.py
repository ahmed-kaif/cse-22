def f(x):
    return (x**3 - 2*x -5)


def Secant(x0, x1, epsilon, N):
    table = []
    f0 = f(x0)
    f1 = f(x1)

    fnp1 = f1 - ((f1 * (x1 - x0))/(f1-f0))
    i = 1
    table.append([i,f0,fnp1,abs(fnp1-f1)])
    while ((abs(fnp1 - f1) >= epsilon) or (i <= N)):
        x0 = x1
        x1 = fnp1
        f0 = f(x0)
        f1 = f(x1)
        fnp1 = f1 - ((f1 * (x1 - x0))/(f1-f0))
        table.append([i,f0,fnp1,abs(fnp1-f1)])

        if (abs(fnp1 - f1) < epsilon):
            printTable(table)
            return fnp1 # root
        i = i+1

    printTable(table)
    return "Failed to converge within the maximum number of iterations"
    

def printTable(table):
    print("Iter |     x_n |    f(x_n)|  |x_{n+1} - x_n|")
    for row in table:
        print(f"{row[0]:4} | {row[1]:8.5f} | {row[2]:8.5f} | {row[3]:8.5f} |")


if __name__ == "__main__":
    x0 = .5
    x1 = 3
    tolerance = 0.0001
    N = 100
    xr = Secant(x0, x1, tolerance,N)
    print(f"The approximate root is: {xr:8.5f}")
