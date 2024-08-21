op = [' + ', ' - ', ' * ', ' // ']
d = dict()

for i in range(4):
    for j in range(4):
        for k in range(4):
            formula = '4'+op[i]+'4'+op[j]+'4'+op[k]+'4'
            ans = eval(formula)
            formula = formula.replace('//', '/')
            ans_str = formula+' = '+str(ans)
            # print(ans_str)
            d[ans] = ans_str
            
for tc in range(1, int(input()) + 1):
    a = int(input())
    if a in d:
        print(d[a])
    else:
        print('no solution')
