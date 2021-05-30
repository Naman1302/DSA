 bool solve(vector<vector<int>> &m,vector<vector<bool>> &vis,int n,int x,int y,vector<string> &ans,string s){
        if(x<0 || y<0 || x>=n || y>=n || vis[x][y] || !m[x][y] ){
            return false;   
        }
        if(x==n-1 and y==n-1){
            ans.push_back(s);
             vis[x][y]=false;
            return true;
        }
        vis[x][y]=true;
        solve(m,vis,n,x+1,y,ans,s+'D');
        solve(m,vis,n,x,y-1,ans,s+'L');
        solve(m,vis,n,x,y+1,ans,s+'R');
        solve(m,vis,n,x-1,y,ans,s+'U');
        vis[x][y]=false;
        return true;    
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        
        if(m[0][0]==0 or m[n-1][n-1]==0)
            return ans;
            
        string s;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        solve(m,vis,n,0,0,ans,s);
        sort(ans.begin(),ans.end());
        return ans;
    }
