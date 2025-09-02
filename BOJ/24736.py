def f(l):
  a = [6, 3, 2, 1, 2]
  return sum(x * y for x, y in zip(l, a))
print(f(list(map(int,input().split()))), sep=' ')
print(f(list(map(int,input().split()))))