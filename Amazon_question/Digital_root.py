import re 
import sys 
def get_string(): return sys.stdin.readline().strip()

def convertTuple(tup): 
    str =  ''.join(tup) 
    return str

def digitalRoot(num): 
    if (num == "0"): 
        return 0
    ans = 0
    for i in range (0, len(num)): 
        ans = (ans + int(num[i])) % 9      
    if(ans == 0): 
        return 9
    else:  
        return ans % 9
        

num = "469" 
print("input")
str1 = get_string()
res = list(re.split(';;;', str1))
ans_list = []
for i in range(len(res)):
    data = re.split(',', res[i])
    final_data = ''.join(data)
    temp = digitalRoot(final_data)
    if(temp % 2 != 0):
        ans_list.append(temp)
print(len(ans_list))