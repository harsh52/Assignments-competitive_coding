'''
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
'''


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        #
        row = len(grid)
        col = len(grid[0])
        #print(row,col)
        temp = [[0 for i in range(col)] for j in range(row)]
        #print(temp)
        
        temp[0][0] = grid[0][0]
        
        for j in range(1,col):
            temp[0][j] = grid[0][j] + temp[0][j-1]
        
        for i in range(1,row):
            temp[i][0] = grid[i][0] + temp[i-1][0]
            
        for i in range(1,row):
            for j in range(1,col):
                temp[i][j] = min(temp[i-1][j],temp[i][j-1]) + grid[i][j]
                
        return(temp[row-1][col-1])
        