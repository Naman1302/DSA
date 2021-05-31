bool issafe(vector<vector<bool>> &board,int r,int c){
        for(int i=0;i<c;i++){
            if(board[r][i])
                return false;
        }
        for(int i=r,j=c;i>=0 and j>=0;i--,j--){
            if(board[i][j])
                return false;
        }
        for(int i=r,j=c;i<board.size() and j>=0;i++,j--){
            if(board[i][j])
                return false;
        }
        return true;
    }
    bool solve(vector<vector<int>> &ans,vector<int> v,vector<vector<bool>> &board,int col,int n){
        if(col==n){
            ans.push_back(v);
            return true;
        }
        bool res=false;
        for(int i=0;i<n;i++){
            
            if(issafe(board,i,col)){
                board[i][col]=true;
                v.push_back(i+1);
                
                res=(solve(ans,v,board,col+1,n)||res);
                
                v.pop_back();
                board[i][col]=false;
            }
            
        }
        return res;
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<int> v;
        vector<vector<bool>> board(n,vector<bool>(n,false));
        
        bool res=solve(ans,v,board,0,n);
        if(!res) return {};
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
