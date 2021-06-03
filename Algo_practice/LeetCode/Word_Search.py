'''
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

'''

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        row = len(board)
        col = len(board[0])
        word = list(word)
        
        def dfs(board,i,j,row,col,count,word):
            if(len(word) == count):
                return True
            if(i<0 or j<0 or i>= row or j>=col or board[i][j] != word[count]):
                return False
            
            temp = board[i][j] 
            board[i][j] = " "
            
            found = (dfs(board,i+1,j,row,col,count+1,word) or # down
                     dfs(board,i-1,j,row,col,count+1,word) or # up
                     dfs(board,i,j-1,row,col,count+1,word) or # left
                     dfs(board,i,j+1,row,col,count+1,word)) #right
            
            board[i][j] = temp
            return(found)
        
        for i in range(row):
            for j in range(col):
                if(board[i][j] == word[0] and dfs(board,i,j,row,col,0,word)):
                    return True
        return False
                