// ques :- https://leetcode.com/problems/snakes-and-ladders/

class Solution {
public:
    vector<int> numse(int next_step,int row)
    {
        int x=(next_step-1)/row;
        int y=(next_step-1)%row;
        if(x%2==1)y=row-1-y;
        x=row-1-x;
        return {x,y};
    }
        
    int snakesAndLadders(vector<vector<int>>& b) {
        int n=b.size();
        queue<int> q;
        q.push(1);
        int ans=0;
        
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int curr=q.front();
                q.pop();
                if(curr==n*n) return ans;
                
                for(int i=1;i<=6;i++){
                    int next=curr+i;
                    if(next>n*n) break;
                    vector<int> pos=numse(next,n);
                    int r=pos[0],c=pos[1];
                    if(b[r][c]!=-1){
                        next=b[r][c];
                    }
                    if(b[r][c]!=(n*n)+1){
                        q.push(next);
                        b[r][c]=(n*n)+1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
