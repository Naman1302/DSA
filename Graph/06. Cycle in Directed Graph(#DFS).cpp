class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool  iscycle(vector<int> adj[],vector<bool> &vis,vector<bool> &rec,int curr){
	    rec[curr]=true;
	    if(!vis[curr]){
	        vis[curr]=true;
	        for(auto i: adj[curr]){
	            if(!vis[i] and iscycle(adj,vis,rec,i)){ //in dfs recursive calls always take i and curr if parent info is needed
	                return true;
	            }
	            if(rec[i]){
	                return true;
	            }
	        }
	    }
	    
	    rec[curr]=false;
	    return false;
	}
	bool isCyclic(int v, vector<int> adj[]) 
	{
	   	vector<bool> vis(v+1,false);
	   	vector<bool> rec(v+1,false); // we maintain a array for elements in our stack while going from one node to other so that if 0->1,0->2,2->3,3->4 dosen't get us a cycle
	   	bool cycle=false;
	   	for(int i=0;i<v;i++){
	   	    if(!vis[i] and iscycle(adj,vis,rec,i)){
	   	        cycle=true;
	   	    }
	   	}
	   	
	   	return cycle;
	}
};
