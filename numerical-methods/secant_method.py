def f(x):
    return x**3 - 2*x - 5  # The function

def Secant(x0, x1, epsilon, N):
    table = []
    f0 = f(x0)
    f1 = f(x1)
    i = 1
    
    # Secant method iterations
    while abs(x1 - x0) >= epsilon and i <= N:
        if f1 == f0:  # Avoid division by zero
            print("Division by zero encountered in Secant method.")
            return None

        # Secant method formula
        x2 = x1 - f1 * (x1 - x0) / (f1 - f0)
        table.append([i, x1, f1, abs(x2 - x1)])
        
        # Update variables for next iteration
        x0, x1 = x1, x2
        f0, f1 = f1, f(x1)
        i += 1

    printTable(table)
    if abs(x1 - x0) < epsilon:
        return x1  # Return the root
    else:
        return "Failed to converge within the maximum number of iterations"

def printTable(table):
    print("Iter |     x_n     |    f(x_n)   |  |x_{n+1} - x_n|")
    print("-------------------------------------------------")
    for row in table:
        print(f"{row[0]:4} | {row[1]:12.5f} | {row[2]:12.5f} | {row[3]:12.5f}")

if __name__ == "__main__":
    x0 = 0.5  # Initial guess x0
    x1 = 3    # Initial guess x1
    tolerance = 0.0001
    N = 100
    xr = Secant(x0, x1, tolerance, N)
    if xr is not None:
        print(f"The approximate root is: {xr:.5f}")
