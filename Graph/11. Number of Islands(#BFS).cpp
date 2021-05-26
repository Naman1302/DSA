class Solution {
public:
    void solve(vector<vector<char>> &g,int x,int y,int n,int m){
        if(g[x][y]=='0'||x<0||y<0||x>n||y>m)
            return;
        g[x][y]='0';
        solve(g,x,y+1,n,m);
        solve(g,x+1,y,n,m);
        solve(g,x,y-1,n,m);
        solve(g,x-1,y,n,m);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0,rows=grid.size(),col=grid[0].size();
        if(rows==0)
            return 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    solve(grid,i,j,rows-1,col-1);
                    count+=1;
                }
            }
        }
        return count;
    }
};
