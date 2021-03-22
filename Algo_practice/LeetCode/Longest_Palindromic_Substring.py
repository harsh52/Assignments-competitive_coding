'''
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
'''

class Solution:
    def longestPalindrome(self, s: str) -> str:
        large = 0
        bool1 = [[0 for i in range(len(s))] for j in range(len(s))]

        count = 0
        str1 = ""
        for g in range(0,len(bool1[0])):
            i = 0
            for j in range(g,len(bool1[0])):

                if(g==0):
                    large = 1
                    bool1[i][j] = 1
                    str1 = s[i:j+1]
                elif(g==1):
                    #print("elif")
                    if(s[i] == s[j]):
                        temp = len(s[i:j+1])
                        if(temp > large):
                            large = temp
                            str1 = s[i:j+1]
                        #large = 2
                        bool1[i][j] = 1
                else:
                    if(s[i] == s[j] and bool1[i+1][j-1] == 1):
                        #print("else")
                        bool1[i][j] = 1
                        temp = len(s[i:j+1])
                        #print(temp,"temp")
                        if(temp > large):
                            #print("in large")
                            #print(s[i:j])
                            large = len(s[i:j+1])
                            str1 = s[i:j+1]

                i += 1
        return(str1)
        