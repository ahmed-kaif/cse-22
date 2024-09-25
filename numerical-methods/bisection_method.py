def f(x):
    return (x**3 - x - 2)
def BisectionMethod(a , b, epsilon, N):
    if f(a) * f(b) >= 0:
        return "Error: f(a) and f(b) must have opposite signs."
    
    table = []
    i = 1
    while i <= N:
        c = (a+b)/2
        fc = f(c)
        table.append([i, a, b, c, f(a), f(b), fc])

        if (abs(fc) < epsilon) or ((b-a)/2 < epsilon):
            printTable(table)
            return c # root
        if f(a)* fc < 0:
            b = c
        else:
            a = c 
        i = i+1

    printTable(table)
    return "Failed to converge within the maximum number of iterations"

def printTable(table):
    print("Iter |     a    |    b     |    c     |   f(a)   |   f(b)   | f(c)")
    for row in table:
        print(f"{row[0]:4} | {row[1]:8.5f} | {row[2]:8.5f} | {row[3]:8.5f} | {row[4]:8.5f} | {row[5]:8.5f} | {row[6]:8.5f}")


if __name__ == "__main__":
    a = 1
    b = 2
    tolerance = 0.001
    N = 20
    xr = BisectionMethod(a,b,tolerance,N)
    print(f"Root found: {xr:8.5f}")
