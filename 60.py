from sympy import sieve, isprime

N = 10000
primes = list(sieve.primerange(N))
primes_set = set(primes)
print(len(primes))

def concat(p, q):
    return int(str(p) + str(q))

def rec_set_find(nums, curr, ans):
    if len(nums) == 5:
        print(nums)
        return sum(nums)
    
    for i in range(curr, len(primes)):
        t = True
        for p in nums:
            if not isprime(concat(p, primes[i])) or not isprime(concat(primes[i], p)):
                t = False
                break
        if not t:
            continue

        nums.append(primes[i])
        ans = min(ans, rec_set_find(nums, i+1, ans))
        nums.pop()
    
    return ans

print(rec_set_find([], 0, 1e9))




    
