class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool iscycle(vector<int> adj[],vector<bool> &vis,int curr,int parent){
	    vis[curr]=true;
	    for(auto i:adj[curr]){
	        if(i != parent){
	            if(vis[i])
	                return true;
	            if(!vis[i] and iscycle(adj,vis,i,curr)){
	                return true;
	            }    
	        }
	    }
	    return false;
	}
	bool isCycle(int v, vector<int>adj[])
	{
	    vector<bool> vis(v+1,false);
	    bool cycle=false;
	    for(int i=0;i<v;i++){
	        if(!vis[i] and iscycle(adj,vis,i,-1)){
	            cycle=true;
	        }
	    }
	    return cycle;
	}
};
