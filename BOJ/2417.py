n=int(input())
s=0
e=n
while s<e:
  q=(s+e)//2
  if q*q<n:
    s=q+1
  else:
    e=q
print(s)