tt = int(input())

for _ in range(tt):
    n = int(input())
    s = input() # 10^3
    
    cnt = 0
    for i in range(0, n - 1):
        if s[i] != s[i + 1]:
            cnt += 1

    if s[0] == '1':
        cnt += 1
    
    print(cnt)
    
