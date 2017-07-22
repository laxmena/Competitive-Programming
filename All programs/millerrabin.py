def check_composite(n, s, d, a):
    x = pow(a, d, n)
    if x == 1 or x == n - 1:
        return False
    for y in range(1, s):
        x = x * x % n
        if x == 1:
            return True
        if x == n - 1:
            return False
    return True

small_primes = set([3,5,7,11,13,17,19,23,29,31,37])
small_is_prime = [s in small_primes for s in range(38)]
small_is_prime[2] = True

witnesses_bounds = [
    (341531, [9345883071009581737]),
    (716169301, [15, 13393019396194701]),
    (154639673381, [15, 176006322, 4221622697]),
    (47636622961201, [2, 2570940, 211991001, 3749873356]),
    (3770579582154547, [2, 2570940, 880937, 610386380, 4130785767]),
]
i64_witnesses = [2, 325, 9375, 28178, 450775, 9780504, 1795265022]


def is_prime(n):
    if n < 38:
        return small_is_prime[n]
    for s in small_primes:
        if n % s == 0:
            return False
    d = n - 1
    s = 0
    while not d & 1:
        d >>= 1
        s += 1
    best_witnesses = i64_witnesses
    for bound, bound_ws in witnesses_bounds:
        if n < bound:
            best_witnesses = bound_ws
            break
    for a in best_witnesses:
        a %= n
        if a and check_composite(n, s, d, a):
            return False
    return True


for cas in range(int(input())):
    n, k = map(int, input().strip().split())

    print (["No", "Yes"][n >= 2*k and (
        k >= 3
        or k == 2 and (not n & 1 or is_prime(n-2))
        or k == 1 and is_prime(n)
    )])