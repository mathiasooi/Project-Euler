from sympy import sieve
import sys

primes = list(sieve.primerange(10000, 1000000))
prime_set = set(primes)

for p in primes:
    s = str(p)
    
    for digit in "0123456789":
        fsize = 0
        for r in "0123456789":
            if r == "0" and s[0] == digit:
                continue
            
            sp = s.replace(digit, r)
            sp = int(sp)
            
            if sp in prime_set:
                fsize += 1
        
        if fsize == 8:
            print(p)
            sys.exit(0)