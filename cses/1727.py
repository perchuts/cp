import decimal
 
# Set precision for decimal operations
decimal.getcontext().prec = 10
 
def main():
    # Read input values from one line
    n, k = map(decimal.Decimal, input().split())  # n and k in one line
    
    ans = decimal.Decimal(0)
    sum_val = decimal.Decimal(0)
    
    # Calculate with precision up to 6 decimal places
    for i in range(1, int(k) + 1):
        i_dec = decimal.Decimal(i)
        cur = decimal.Decimal(1)
        tmp = decimal.Decimal(1)
        
        # Inner loop for calculating cur and tmp
        for j in range(1, int(n) + 1):
            cur *= max(decimal.Decimal(1), i_dec - 1) / k
            tmp *= i_dec / k
        
        if i != 1:
            cur = tmp - cur
        
        ans += i_dec * cur
        sum_val += cur
 
    # Print the result with fixed precision
    print(f"{ans:.6f}")
 
if __name__ == "__main__":
    main()
 
