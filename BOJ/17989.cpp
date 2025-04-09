from heapq import heappush, heappop
targetTitle = "Jane Eyre"

n, m, k = map(int, input().split())

pq = []
present = []
for i in range(n):
  s = input()
  title, page = s.split('"')[1:]
  page = int(page.strip())
  heappush(pq, (title, page))
for i in range(m):
  s = input()
  st, title, page = s.split('"')
  st = int(st.strip())
  page = int(page.strip())
  present.append((st, title, page))

present.sort(reverse=True)
heappush(pq, (targetTitle, k))

ans = 0
while pq:
  title, page = heappop(pq)
  ans += page
  if title == targetTitle:
    break
  while present and present[-1][0] <= ans:
    heappush(pq, present[-1][1:])
    present.pop()

print(ans)