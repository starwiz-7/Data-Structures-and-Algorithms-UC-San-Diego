# Author: Aryan Yadav
k = {}
for _ in range(int(input())):
    a = list(map(str, input().split()))
    if a[0] == "add":
        k[a[1]] = a[2]
    elif a[0] == "find":
        if a[1] in k:
            print(k[a[1]])
        else:
            print("not found")
    else:
        if a[1] in k:
            del k[a[1]]
