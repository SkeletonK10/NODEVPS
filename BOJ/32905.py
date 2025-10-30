n=int(input().split()[0])
for i in range(n):
  if input().count('A') != 1:
    print('No')
    exit(0)
print('Yes')