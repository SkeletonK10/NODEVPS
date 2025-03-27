a,b=map(int,input().split())
print(sum([i for s in [[y]*y for y in range(99)] for i in s][a-1:b]))
