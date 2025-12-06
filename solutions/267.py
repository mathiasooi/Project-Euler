import math
from numpy import linspace  
from scipy.stats import binom
import functools

BILLION = 1e9

def exp_val(f, heads):
    # The expected amount of money
    return math.pow(1+2*f, heads) * math.pow(1-f, 1000-heads)

def min_heads():
    # Minimizes heads so that expected money is > 1 billion
    h = 1001
    for f in linspace(0, 1, 1000):
        for heads in range(1, 1000):
            if heads > h: break
            if exp_val(f, heads) >= BILLION:
                h = min(h, heads)
                break
    return h

def solve():
    heads = min_heads()
    # Calculate probability of getting >= heads given fair coin
    # Find binomial_cdf(heads, 1000, 0.5)
    binom_coeff = [[1] + [0]*heads for i in range(1001)]
    px = [1] + [0]*1000

    for i in range(1, 1001):
        for j in range(1, heads+1):
            binom_coeff[i][j] = binom_coeff[i-1][j-1] + binom_coeff[i-1][j]
    for i in range(1, 1001):
        px[i] = 0.5 * px[i-1]

    ans = 1
    for h in range(heads):
        ans -= binom_coeff[1000][h] * px[h] * px[1000-h]
    
    print(round(ans, 12))

if __name__ == "__main__":
    # heads = min_heads()
    # ans = 1 - binom.cdf(heads-1, 1000, 0.5)
    # print(round(ans, 12))
    solve()
    