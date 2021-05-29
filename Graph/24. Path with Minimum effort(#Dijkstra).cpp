// Q -> https://leetcode.com/problems/path-with-minimum-effort

class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    bool isvalid(int x,int y,int n,int m){
        if(x>=0 and x<n and y>=0 and y<m)
            return true;
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row=heights.size(),col=heights[0].size();
        
        vector<vector<int>> adj(row,vector<int> (col,INT_MAX));
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        adj[0][0]=0;
        while(!pq.empty()){
            pair<int,pair<int,int>> t=pq.top();
            pq.pop();
            pair<int,int> q=t.second;
            int a=t.first;
            int b=q.first;
            int c=q.second;
            if(vis[b][c]) continue;
            vis[b][c]=true;
            for(int i=0;i<4;i++){
                int x=b+dx[i];
                int y=c+dy[i];
                if(isvalid(x,y,row,col)){
                    int val=max(adj[b][c],abs(heights[x][y]-heights[b][c]));  //dp type...
                    if(val<adj[x][y]){                                       //..........
                        adj[x][y]=val;                                      //..........
                        pq.push({val,{x,y}});                              //..........
                    }
                }
            }
        }
        return adj[row-1][col-1];
    }
};
