from math import ceil

def solve(a, b, c):
    l = 0; r = 1e18
    while r - l > 1:
        m = int(l + (r - l) / 2)
        if a * m * m + b * m + c <= 0:
            l = int(m)
        else:
            r = int(m)
    if a * l * l + b * l + c == 0:
        return l
    return -1


n = int(input())

i = 1
while i * i * i <= n:
    #(k+d)^3 - k^3 = d^3 + 3*d^2k + 3*d*k^2 = n
    if n % i == 0: 
        i += 1
        continue
    m = int(n / i)
    k = solve(3, 3*i, i*i - m)
    if k > 0:
        print(f"{k + i} {i}")
        exit()
    i += 1
print(-1)