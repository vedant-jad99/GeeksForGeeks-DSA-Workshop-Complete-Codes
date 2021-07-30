/*
Link to the question
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int prev = image[sr][sc];
        fill(image, sr, sc, newColor, prev);
        
        return image;
    }
    bool isValid(int r, int c, int n, int m) {
        if(r < n && r >= 0 && c < m && c >= 0)
            return true;
        return false;
    }
    void fill(vector<vector<int>>& image, int r, int c, int newColor, int prev) {
        if(isValid(r, c, image.size(), image[0].size())) {
            if(image[r][c] != prev)
                return;
            
            if(image[r][c] == newColor)
                return;
            
            image[r][c] = newColor;
            fill(image, r + 1, c, newColor, prev);
            fill(image, r, c + 1, newColor, prev);
            fill(image, r - 1, c, newColor, prev);
            fill(image, r, c - 1, newColor, prev);
        }
        
        return;
    }
};
