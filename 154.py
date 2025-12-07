import numpy as np
from tqdm import trange
import math

N = 200000
twos, fives = np.zeros(N+1), np.zeros(N+1)

for i in range(N+1):
    n = i
    while n % 2 == 0 and n:
        twos[i] += 1
        n //= 2

    n = i
    while n % 5 == 0 and n:
        fives[i] += 1
        n //= 5

psum2 = np.cumsum(twos)
psum5 = np.cumsum(fives)

def multinomial(psum, n, a, b, c):
    return psum[n] - psum[a] - psum[b] - psum[c]

ans = 0
chunk_size = 10000
for a in trange(N+1):
    for start in range(0, N+1-a, chunk_size):
        b = np.arange(start, min(N+1-a, start+chunk_size))
        c = N - a - b
        val2 = psum2[N] - psum2[a] - psum2[b] - psum2[c]
        val5 = psum5[N] - psum5[a] - psum5[b] - psum5[c]
        ans += np.sum((val2 >= 12) & (val5 >= 12))
print(ans)