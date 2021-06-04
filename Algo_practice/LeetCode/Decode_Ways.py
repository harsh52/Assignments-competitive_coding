'''
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.


Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

'''




class Solution:
    def numDecodings(self, s: str) -> int:
        s = list(s)
        #print(s)
        dp = [0 for _ in range(len(s))]
        dp[0] = 1
        
        if(len(s) == 1 and s[0] == '0'):
            return 0
        
        if(s[0] == '0'):
            dp[0]=0
        
        for i in range(1,len(s)):
            print(s)
            #print("in loop")
            if(s[i-1] == '0' and s[i] == '0'):
                dp[i] = 0
            elif(s[i-1] == '0' and s[i] != '0'):
                #print("in second")
                dp[i] = dp[i-1]
            elif(s[i-1] != '0' and s[i] == '0'):
                #print("here")
                if(s[i-1] == '1' or s[i-1] == '2'):
                    dp[i] = (dp[i-2] if i>=2 else 1)
                    print(dp)
                else:
                    dp[i]=0
            else:
                #print("in last")
                temp = ''.join(map(str,s[i-1:i+1]))
                if(int(temp) <= 26):
                    dp[i] = dp[i-1] + (dp[i-2] if i>=2 else 1)
                
                else:
                    dp[i] = dp[i-1]
        #print("test")    
        return(dp[-1])
        