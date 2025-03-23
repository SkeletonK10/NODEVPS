s1=int(input())
s2=0
for i in range(int(input())):
    a,b=map(int,input().split())
    s2+=a*b
print("Yes" if s1==s2 else "No")