bool1 = [[i*j for i in range(5)] for j in range(5)]

print(bool1)
for g in range(0,len(bool1[0])):
    i = 0
    for j in range(g,len(bool1[0])):
        print(bool1[i][j])
        i += 1