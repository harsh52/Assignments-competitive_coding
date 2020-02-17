dict1 = {}
def orangecap(d):
    #print("d")
    for key,value in d.items():
        #k2 = 0
        #print("t")
        for k,v in value.items():
            if k in dict1:
                dict1[k] = dict1[k]+v
            else:
                dict1[k] = v
    v2 = max(dict1.values())
    for k,v in dict1.items():
        if v == v2:
            return k,v