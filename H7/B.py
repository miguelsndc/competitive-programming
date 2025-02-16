a, op, b = input().split(' ')

mod = 1000000007
a = int(a)
b = int(b)

if op == '+':
    print(((a % mod) + (b % mod)) % mod)
elif op == '^':
    b = b % (mod - 1)
    print(pow(a, b, mod))
elif op == '*':
    print(((a % mod) * (b % mod)) % mod)
elif op == '-':
    print((((a % mod) - (b % mod))) % mod)