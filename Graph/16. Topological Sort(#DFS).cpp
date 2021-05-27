class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(vector<int> adj[],vector<bool> &vis,stack<int> &s,int curr){
	    vis[curr]=true;//visiting
	    for(auto i:adj[curr]){
	        if(!vis[i]){
	            dfs(adj,vis,s,i);//visiting adjacents
	        }
	    }
	    s.push(curr);//now all adjacent's are travelled,so we push curr element in stack as discussed below.
	}
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    stack<int> s;//if we use direct dfs then we might have problem as dfs goes on in depth but for top sort we need to print a vertex before its adjacent vertices.Thus, we maintain stack to store all vertex whose vertices are travelled
	    vector<int> ans;
	    vector<bool> vis(v,false);
	    for(int i=0;i<v;i++){
	        if(!vis[i])
	          dfs(adj,vis,s,i);  
	    }
	    while(!s.empty()){
	        int t=s.top();
	        s.pop();
	        ans.push_back(t);
	    }
	    return ans;
	}
};
