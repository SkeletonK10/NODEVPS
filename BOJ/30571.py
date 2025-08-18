def alpha(n):
  ret = ''
  while n:
    n, r = divmod(n, 26)
    ret = chr(r + ord('a')) + ret
  return ret or 'a'

d = dict()
for i in range(int(input())):
  s = input()[:-1].split('.')
  if (len(s) == 1):
    s.append('0')
  key = (s[0].lstrip('0'), s[1].rstrip('0'))
  if key not in d:
    d[key] = alpha(len(d))
  print(d[key])