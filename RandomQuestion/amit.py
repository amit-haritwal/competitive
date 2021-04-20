v1 = list(map(int, input().split(',')))
ans = []

for i in range(0, len(v1)):
    d = {}
    for j in range(i+1, len(v1)):
        if v1[j] > v1[i]:
            if v1[j] in d:
                d[v1[j]] = d[v1[j]] + 1
            else:
                d[v1[j]] = 1
    if(not bool(d)):
        min1 = -1
    else:
        occ = 0
        min1 = 99999999
        d = sorted(d, key=lambda val: val.key)
        for state, state1 in d.items():
            if (state1 > occ):
                min1 = state
                occ = state1
    ans.append(min1)
for i in range(0, len(ans)):
    if (i == len(ans) - 1):
        print(ans[i])
    else:
        print(ans[i], end=",")
