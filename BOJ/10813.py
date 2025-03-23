n,m=map(int,input().split())
a=list(range(n+1))
for i in range(m):
    x,y=map(int,input().split())
    a[x],a[y]=a[y],a[x]
print(*a[1:])