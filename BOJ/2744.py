a = input()
s = ''
for c in a:
  if c.isupper():
    s += c.lower()
  else :
    s += c.upper()
    print(s)