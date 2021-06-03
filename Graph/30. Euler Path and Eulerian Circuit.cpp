    void dfs(int curr,vector<int> adj[],vector<bool> &vis){
        vis[curr]=true;
        for(auto i : adj[curr]){
            if(!vis[i])
                dfs(i,adj,vis);
        }
    }
    bool is_connected(vector<int> adj[],int v){
        vector<bool> vis(v,false);
        int node=INT_MAX;
        for(int i=0;i<v;i++){
            if(adj[i].size()!=0)
            {
                node=i;
                break;
            }    
        }
        
        if(node==INT_MAX){
            return true;
        }
        dfs(node,adj,vis);
        for(int i=0;i<v;i++){
            if(!vis[i] and adj[i].size()>0)
                return false;
        }
        
        return true;
    }
	int isEularCircuit(int V, vector<int>adj[]){
	    if(is_connected(adj,V)==false)
	        return 0;
	    int odd=0;
	    for(int i=0;i<V;i++){
	        if(adj[i].size() & 1)
	            odd++;
	    }
	    if(odd>2)
	        return 0;
	   return (odd) ? 1 : 2;
	}
