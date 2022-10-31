n = int(input())

if n == 1:
    print(1)
else:
    i = 2
    while i <= n:
        while n % i == 0:
            print(i)
            n /= i
        i += 1