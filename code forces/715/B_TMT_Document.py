t = int(input())
while t:
    s = int(input())
    str = list(input())
    l = 0
    m = 0
    r = 0
    v1 = []
    flag = 0
    for i in str:
        if i == 'T':
            v1.append('T')
        else:
            if len(v1) == 0:
                flag = 1
                break
            v1.pop()
            m = m + 1
    if flag == 0 and m == len(v1):
        print("YES")
    else:
        print("NO")
    t = t - 1
