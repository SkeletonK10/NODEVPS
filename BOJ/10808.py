from functools import reduce
def f(l,x):
  l[ord(x)-97]+=1
  return l
print(*reduce(f,input(),[0]*26))