from sympy import isprime
import sys

# primes = list(sieve.primerange(1000000))
# prime_set = set(primes)

a = lambda n: 4*n*n - 2*n + 1
b = lambda n: 4*n*n + 1
c = lambda n: 4*n*n + 2*n + 1

cnt = 0
for n in range(1, 1000000):
    cnt += isprime(a(n))
    cnt += isprime(b(n))
    cnt += isprime(c(n))

    if cnt / (4.0*n+1) < 0.1:
        print(2*n+1)
        sys.exit(0)


