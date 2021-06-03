//same as path finding 
class Solution {
public: 
    bool isValid(int sr, int sc, int m, int n){ //checks given coordinates are valid or not
        if(sr >= 0 && sr < m && sc >= 0 && sc < n) return true;
        return false;
    }
    void dfs(vector<vector<int>>& image, int m, int n, vector<vector<bool>> &visited, int sr, int sc, int newColor, int oldColor){
        visited[sr][sc] = true;
        if(oldColor == image[sr][sc]) // Matching found
            image[sr][sc] = newColor;   

            if(isValid(sr, sc+1, m, n) && !visited[sr][sc+1]){    //right
                dfs(image, m, n, visited, sr, sc+1, newColor, oldColor);
            }
            if(isValid(sr, sc-1, m, n) && !visited[sr][sc-1]){    //left
                dfs(image, m, n, visited, sr, sc-1 , newColor, oldColor);
            }
            if(isValid(sr-1, sc, m, n) && !visited[sr-1][sc]){    //up
                dfs(image, m, n, visited, sr-1, sc, newColor, oldColor);
            }
            if(isValid(sr+1, sc, m, n) && !visited[sr+1][sc]){    //down
                dfs(image, m, n, visited, sr+1, sc, newColor, oldColor);
            }
        }    
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        
        dfs(image, m, n, visited, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};
