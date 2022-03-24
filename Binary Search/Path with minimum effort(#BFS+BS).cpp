class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
	
    bool isvalid(int x,int y,int n, int m){
    return (x>=0 && x<n && y>=0 && y<m);
	
}
    bool bfs(vector<vector<int>> heights,int k) {//max difference cn be k between any two heights
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        vector<vector<bool>>visited(101,vector<bool>(101,false));
        visited[0][0]=1;
		
        while(!q.empty()) {
        pair<int,int>curr = q.front();
        q.pop();
        int cx = curr.first;
        int cy = curr.second; 
        if(cx == heights.size()-1 && cy==heights[0].size()-1)
            return true;
        for(int i=0;i<4;i++) {
            int x = dx[i] + cx;
            int y = dy[i] + cy;
            if(isvalid(x,y,heights.size(),heights[0].size()) && !visited[x][y] ){
                if( abs(heights[cx][cy]-heights[x][y]) <= k){
                    visited[x][y] = true;
                    q.push(make_pair(x,y));
                }
            }
        }
     }
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l=0;//min diff in heights
        int r = 1e6;//max diff in heights
      //we need to minimise the max difference that can be taken between two points
        while(l<r) {
            int m = l+(r-l)/2;
            if(bfs(heights,m))
                r=m;//if possible then greater height will be ignored
            else 
                l=m+1;//else smaller heihts will be ignored
        }
        return l;//we can take in l diff. in heights so that path with min effort will be found out.
    }
};
