t = int(input())
while t:
    n = int(input())
    v1 = list(map(int, input().split()))
    v2 = []
    for i in v1:
        if i % 2 == 0:
            print(i, end=" ")
        else:
            v2.append(i)
    for j in v2:
        print(j, end=" ")
    print("")
    t = t-1
