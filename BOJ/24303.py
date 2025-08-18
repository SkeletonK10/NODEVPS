l = list(map(int, input().split()))
t = [(l[i], l[i + 3]) for i in range(3)]
ans = 0
for (a, b) in sorted(t, reverse=True):
    for j in range(b):
        l[6] -= a
        ans += 1
        if l[6] <= 0:
            print(ans)
            exit()
print(0)