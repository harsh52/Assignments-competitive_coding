'''
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
'''



class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        no_of_island = 0
        row = len(grid)
        col = len(grid[0])
        #print(row,col)
        
        def dfs(grid,i,j,row,col):
            if(i<0 or j<0 or i>= row or j>= col or grid[i][j] != '1'):
                return
            
            grid[i][j] = "2"
            dfs(grid,i+1,j,row,col) #bottom
            dfs(grid,i-1,j,row,col) #top
            dfs(grid,i,j-1,row,col) #left
            dfs(grid,i,j+1,row,col) #right
            
        
        for i in range(row):
            for j in range(col):
                if(grid[i][j] == "1"):
                    dfs(grid,i,j,row,col)
                    no_of_island = no_of_island + 1
        
        return(no_of_island)
                    