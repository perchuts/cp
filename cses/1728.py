from decimal import Decimal, getcontext, ROUND_HALF_EVEN

def main():
    getcontext().prec = 50  # Set precision to 50 decimal places
    getcontext().rounding = ROUND_HALF_EVEN  # Set rounding mode to half to even
    
    n = int(input())
    r = list(map(int, input().split()))

    ans = Decimal(0)

    for i in range(n):
        for j in range(i + 1, n):
            k = Decimal(0)  # k = quantidade de inversoes
            if r[i] <= r[j]:
                k = (Decimal(r[i]) * (Decimal(r[i]) - 1)) / 2
            else:
                k = (Decimal(r[j]) * (Decimal(r[j]) - 1)) / 2 + Decimal(r[j]) * (Decimal(r[i]) - Decimal(r[j]))
            ans += k / (Decimal(r[i]) * Decimal(r[j]))

    # Applying rounding half to even when printing the result
    print(f"{ans.quantize(Decimal('0.000001'))}")

if __name__ == "__main__":
    main()

