class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(vector<int> rev[],vector<bool> &vis,int curr){
	    vis[curr]=true;
	    for(auto i:rev[curr]){
	        if(!vis[i])
	            dfs(rev,vis,i);
	    }
	}
	void solve(vector<bool> &visited,vector<int> adj[],stack<int> &s,int curr){
	    visited[curr]=true;
	    for(auto i:adj[curr]){
	        if(!visited[i])
	            solve(visited,adj,s,i);
	    }
	    s.push(curr);
	}
    int kosaraju(int v, vector<int> adj[])
    {
        stack<int> s;
        vector<bool> visited(v,false);
        for(int i=0;i<v;i++){
            if(!visited[i])
                solve(visited,adj,s,i);
        }
        vector<int> rev[v];
        
        for(int i=0;i<v;i++){
	        for(auto j:adj[i]){
	            rev[j].push_back(i);
	        }
	    }
        int count=0;
        vector<bool> vis(v,false);
        while(!s.empty()){
            int t=s.top();
            s.pop();
            if(vis[t]==false){
                dfs(rev,vis,t);
                count++;
            }
        }
        return count;
    }
};
