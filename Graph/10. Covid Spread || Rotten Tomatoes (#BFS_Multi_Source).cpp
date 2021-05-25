class Solution {
public:
    bool solve(vector<vector<int>> &hospital,int x,int y,int r,int c){
        if(x>=0 and x<r and y>=0 and y<c and hospital[x][y]==1)
            return true;
        return false;
    }
    int helpaterp(vector<vector<int>> hospital)
    {
        queue<pair<int,int>> q;
        for(int i=0;i<hospital.size();i++){
            for(int j=0;j<hospital[0].size();j++){
                if(hospital[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int t=-1,r=hospital.size(),c=hospital[0].size();
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(solve(hospital,x-1,y,r,c)){
                    q.push({x-1,y});
                    hospital[x-1][y]=2;
                }
                if(solve(hospital,x+1,y,r,c)){
                    q.push({x+1,y});
                    hospital[x+1][y]=2;
                }
                if(solve(hospital,x,y-1,r,c)){
                    q.push({x,y-1});
                    hospital[x][y-1]=2;
                }
                if(solve(hospital,x,y+1,r,c)){
                    q.push({x,y+1});
                    hospital[x][y+1]=2;
                }
            }
            t++;
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(hospital[i][j]==1)
                    return -1;
            }
        }
        return t;
    }
};
