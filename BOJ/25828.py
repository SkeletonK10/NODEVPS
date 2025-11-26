g, p, t = map(int, input().split())
every = g * p
group = g + p * t
if every < group:
  print(1)
elif every > group:
  print(2)
else:
  print(0)