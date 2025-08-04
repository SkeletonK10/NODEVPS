N = int(input())
s = int(input().split('.')[1])
ans = 0
for i in range(N):
  s += int(input().split('.')[1])
  if s % 100:
    ans += 1
print(ans)