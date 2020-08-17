s = [2, 3, 1, 4, 5] 
li=[] 
  
for i in range(len(s)): 
      li.append([s[i],i]) 
print(li)
li.sort() 
sort_index = [] 
print(li)
for x in li: 
      sort_index.append(x[1]) 
  
print(sort_index)