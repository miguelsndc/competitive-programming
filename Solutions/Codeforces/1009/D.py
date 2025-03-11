for _ in range(int(input())):
    n, m = map(int, input().split(' '))
    X = list(map(int, input().split(' ')))
    R = list(map(int, input().split(' ')))
    seen = {}
    for x, r in zip(X,R):
        for xi in range(x-r, x+r+1):
            if xi not in seen:
                seen[xi] = 0
            seen[xi] = max(seen[xi], r*r - (x-xi)**2) # y² 
    print(sum(2 * int(h ** 0.5) + 1 for h in seen.values()))
