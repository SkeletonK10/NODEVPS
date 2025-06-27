N = int(input())
l = [input().split() for i in range(N)]
l.sort(key=lambda sp: int(sp[1]))
for s,i,d in l:
  print(s[int(d)-1].capitalize(), end='')