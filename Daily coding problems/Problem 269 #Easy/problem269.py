class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        fallen = [i for i in dominoes]
        i, n = 0, len(dominoes)
        bookmarks = []
        
        while i < n:
            if dominoes[i] == '.':
                pass
            elif dominoes[i] == 'L':
                bookmarks.append(('L', i - 1))
            else:
                j = i + 1
                latest = i
                while j < n and dominoes[j] != 'L':
                    if dominoes[j] ==  'R':
                        latest = j
                    fallen[j] = 'R'
                    j += 1
                
                if j == n:
                    break
                
                bookmarks.append(('R', latest, j))
                i = j
            i += 1
                    
        for i in bookmarks:
            if i[0] == 'L':
                var = i[1]
                while var >= 0:
                    if dominoes[var] == 'L':
                        break
                    fallen[var] = 'L'
                    var -= 1
            
            if i[0] == 'R':
                start, end = i[1] + 1, i[2] - 1
                while start < end:
                    fallen[end] = 'L'
                    start += 1
                    end -= 1
                
                if start == end:
                    fallen[end] = '.'
                
            
        return "".join(fallen)
