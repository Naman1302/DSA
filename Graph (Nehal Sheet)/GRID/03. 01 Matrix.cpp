class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& m) {
        int x[4]={0,1,0,-1};
        int y[4]={1,0,-1,0};
        queue<pair<int,int>> q;
        vector<vector<int>> ans(m.size(),vector<int>(m[0].size(),INT_MAX));
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto f=q.front();
                q.pop();
                int r=f.first,c=f.second;
                for(int i=0;i<4;i++){
                    int a=r+x[i];
                    int b=c+y[i];
                    if(a<0||b<0||a>=m.size()||b>=m[0].size()||m[a][b]==0){
                        continue;
                    }
                    ans[a][b]=min(ans[a][b],ans[r][c]+1);
                    m[a][b]=0;
                    q.push({a,b});
                }
            }
        }
        return ans;
    }
};
