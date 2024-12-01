def factorial(n):
    """Calculate factorial of a number."""
    if n == 0 or n == 1:
        return 1
    return n * factorial(n - 1)

def central_difference_table(y_values):
    """Construct the central difference table."""
    n = len(y_values)
    diff_table = [y_values[:]]  # Initialize with the original y-values

    for i in range(1, n):
        # Calculate differences for each order
        differences = [diff_table[-1][j + 1] - diff_table[-1][j] for j in range(len(diff_table[-1]) - 1)]
        diff_table.append(differences)
    
    return diff_table

def gauss_central_difference(x_values, y_values, target_x):
    h = x_values[1] - x_values[0]  # Spacing between x values
    n = len(x_values)

    # Calculate p
    mid_index = n // 2  # Find the center index
    x0 = x_values[mid_index]  # Center value
    p = (target_x - x0) / h

    # Construct the central difference table
    diff_table = central_difference_table(y_values)

    # Initialize the interpolated value
    result = y_values[mid_index]
    term = 1
    sign = 1

    for i in range(1, len(diff_table)):  # Loop over valid central difference orders
        if i % 2 != 0:
            index = mid_index - i // 2
        else:
            index = mid_index - i // 2 + 1

        # Check if index is within bounds for the current row in the diff_table
        if index < 0 or index >= len(diff_table[i]):
            break  # Exit the loop if the index goes out of bounds

        term *= (p - (i - 1) / 2) if i % 2 != 0 else (p + (i - 1) / 2)
        term /= i
        result += sign * term * diff_table[i][index]
        sign *= -1  # Alternate signs

    return result

def main():
    # Take inputs from the user
    n = int(input("Enter the number of data points: "))
    print("Enter the x values (evenly spaced):")
    x_values = [float(input(f"x[{i}]: ")) for i in range(n)]

    print("Enter the corresponding y values:")
    y_values = [float(input(f"y[{i}]: ")) for i in range(n)]

    target_x = float(input("Enter the value of x to interpolate: "))

    # Validate spacing of x-values
    h = x_values[1] - x_values[0]
    if not all(abs(x_values[i] - x_values[i - 1] - h) < 1e-6 for i in range(2, n)):
        print("Error: x values must be evenly spaced.")
        return

    # Perform Gauss Central Difference interpolation
    interpolated_value = gauss_central_difference(x_values, y_values, target_x)
    print(f"Interpolated value at x = {target_x}: {interpolated_value:.5f}")

if __name__ == "__main__":
    main()
