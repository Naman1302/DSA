class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	void DFSUtil (int i,vector <int> adj[],int V,bool vis[],vector<int> &res)
	{
	    if (vis[i]) 
	        return;
	        
	    //marking vertex as visited and adding it to output list.
	    vis[i] = true;
	    res.push_back (i);
	    
	    //iterating over connected components of the vertex and if any 
	    //of them is not visited then calling the function recursively.
	    for (int j : adj[i])
	    {
	        if (!vis[j])
	            DFSUtil (j, adj, V, vis, res);
	    }
	}
    
    //Function to return a list containing the DFS traversal of the graph.
	vector <int> dfsOfGraph(int V, vector<int> adj[])
	{
	    //using a boolean list to mark all the vertices as not visited.
	    bool vis[V];
	    memset (vis, false, sizeof (vis));
	
	    vector <int> res;
	    for (int i = 0;i < V; i++)
	    {
	        //if any vertex isn't visited then calling the function.
	        if (!vis[i])
	        {
	            DFSUtil (i, adj, V, vis, res);
	        }
	    }
	    //returning the output list.
	    return res;
	}
};
