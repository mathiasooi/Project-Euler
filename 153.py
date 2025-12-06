import numpy as np
from tqdm import tqdm
import math


N = int(1e8)

sum_to_div = np.zeros(N+1, dtype=np.int64)
for i in range(1, N+1):
    sum_to_div[i::i] += i

psum = np.cumsum(sum_to_div)

ans = 0

ub = int(math.sqrt(N)) + 1
for a in range(1, ub):
    for b in range(ub):
        if a*a + b*b > N: break 
        
        if math.gcd(a, b) == 1:
            k = N // (a*a + b*b)
            # print(a, b, psum[k])
            ans += (a + b) * psum[k]

print(ans)