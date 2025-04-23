def getAll(groupDict, vst, groupName):
  if not groupName in groupDict:
    return 1
  res = 0
  for member in groupDict[groupName]:
    if member not in vst:
      vst.add(member)
      res += getAll(groupDict, vst, member)
  return res

while True:
  ansGroup = ''
  groupDict = dict()
  n = int(input())
  if n == 0: break
  for i in range(n):
    group, names = input().split(':')
    nameSet = set(names.strip('.').split(','))
    groupDict[group] = nameSet
    if i == 0:
      ansGroup = group
  print(getAll(groupDict, set(), ansGroup))