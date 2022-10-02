//LEETCODE - 200. Number of Islands
from collections import deque
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def is_valid(i,j, grid):
            if i>=0 and i<len(grid) and j>=0 and j<len(grid[0]):
                return True
            return False
        
        def bfs(i, j, visited, grid):
            q = deque()
            q.append((i,j))
            visited.add((i,j))
            dir = [[-1,0],[1,0],[0,-1],[0,1]]
            while q:
                x, y = q.popleft()
                for d in range(4):
                    new_x = x+dir[d][0]
                    new_y = y+dir[d][1]
                    if is_valid(new_x, new_y,grid) and grid[new_x][new_y]=="1" and (new_x, new_y) not in visited:
                        q.append((new_x, new_y))
                        visited.add((new_x, new_y))
            return 1
                        
        visited = set()
        numIsl = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1" and (i,j) not in visited:
                    numIsl += bfs(i, j, visited, grid)
                    
        return numIsl
