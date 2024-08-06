def quadratic_solution(a, b, c):
    plus_minus = (b**2 - 4*a*c)**0.5
    return (-b+plus_minus)/(2*a)

def collide(m1, m2, v1, v2):
    a = m1 + m2*((m1/m2)**2)
    b = m1*2*v1 - m2*2*(m1/m2)*v2
    c = 0   # initial energy term removed
    x = quadratic_solution(a,b,c)
    return v1+x, v2-(x*(m1/m2))

def P6(n):
    # ADD ADDITIONAL CODE HERE!
    m1 = 1
    m2 = n
    v1 = 0
    v2 = 1
    ans = 0
    while v1 > 0 or v2 > 0 or v1 <= v2:
        v1, v2 = collide(m1, m2, v1, v2)
        ans += 1
        if v1 > 0:
            v1 = -v1
            ans += 1
    return ans
