input()
s=sorted(set(map(int,input().split()))-set(map(int,input().split())))
print(len(s))
print(*s)