import time

MAX_PRIME = 10000

# 직관적인 코드
start = time.time()
for i in range(2, MAX_PRIME + 1):
    ok = True
    for j in range(2, i):
        if i % j == 0:
            ok = False
            break
    if ok:
        print(i, end = ' ')
end = time.time()
print('\n%.7f' % (end - start))

# 에라토스테네스의 체 구현
start = time.time()
isPrime = [True] * (MAX_PRIME + 1)
i = 2
while i * i <= MAX_PRIME:
    if isPrime[i]:
        for j in range(i * i, MAX_PRIME + 1, i):
            isPrime[j] = False
    i = i + 1
for i in range(2, MAX_PRIME + 1):
    if isPrime[i]:
        print(i, end = ' ')
end = time.time()
print('\n%.7f' % (end - start))