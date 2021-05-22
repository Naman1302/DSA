bool solve(vector<int> adj[],int curr,vector<int> &color){
        queue<int> q;
        q.push(curr);
        color[curr]=0;
        while(!q.empty()){
            int node=q.front();
            int c=color[node];
            q.pop();
            for(auto i:adj[node]){
                if(i==node)
                    return false;
                if(color[i]==c)
                    return false;
                if(color[i]==-1){
                    color[i]=c^1;
                    q.push(i);
                }    
            }
        }
        
        return true;
    }
	bool isBipartite(int v, vector<int>adj[]){
	    // Code here
	    vector<int> color(v,-1);
	 
	    for(int i=0;i<v;i++){
	        if(color[i]==-1){
	           if(!solve(adj,i,color)) 
	           return false;
	        }
	    }
	    return true;
	}
