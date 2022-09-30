from sortedcontainers import SortedList
class Solution:
    def getSkyline(self, A: List[List[int]]) -> List[List[int]]:
        
        # Sorted list to keep track of ending X-coordinate of building (with index of building in original array)
        sEnd = SortedList()
        # Sorted list to keep track of Y-coordinates (i.e. heights) of all current buildings that haven't ended yet (with index of building in original array)
        sHt = SortedList()

        res = []

        # Helper method to insert into the result array (check previously inserted adjacent height (y-coordinate) as well as the x-coordinate)
        def insertIntoRes(x, h):
            if res and res[-1][0] == x:
                res.pop()
            if not res or res[-1][1] != h:
                res.append((x,h))
        
        # Helper method to handle the case where a building is ending when traversing from left to right
        def handleEndOfBuilding():
            end, idx = sEnd.pop(0)
            if sHt[-1] == (A[idx][2], idx):
                sHt.pop()
                if sHt:
                    insertIntoRes(end, sHt[-1][0])
                else:
                    insertIntoRes(end, 0)
            else:
                sHt.remove((A[idx][2], idx))
        
        
        # Main
        
        for i,x in enumerate(A):
            x1,x2,y = x
            
            while sEnd and sEnd[0][0] <= x1:
                handleEndOfBuilding()
            
            sEnd.add((x2,i))
            sHt.add((y,i))
            
            if sHt:
                insertIntoRes(x1,sHt[-1][0])
            else:
                insertIntoRes(x1, 0)
            # print(res)
        
        while sEnd:
            handleEndOfBuilding()
        
        return res