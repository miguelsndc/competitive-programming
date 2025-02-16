n = int(input())
mod = 1000000007
for i in range(n):
    a, b, c = map(int, input().split(' '))
    # 10000000007 É PRIMO PO*8RSP8 !!!!!!!!!!!!!!!!!!!!!!!!!!
    print(pow(a, pow(b, c, mod-1), mod))