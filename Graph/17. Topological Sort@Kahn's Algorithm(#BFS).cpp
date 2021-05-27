vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    queue<int> q;
	    vector<int> ans;
	    vector<int> indegree(v,0);//indegre is number of nodes coming to our taken node i.e. 0->2 means 0 has indegree of 1initially 0
	    for(int i=0;i<v;i++){
	       for(auto x:adj[i])
	           indegree[x]++;//as mentioned above
	    }
	    for(int i=0;i<v;i++){
	        if(indegree[i]==0)//if some one has 0 indegree that means it's free and had no one to come before him so,we''l take it in our queue so that we can take it ans remove its indegree from all adjacents
	           q.push(i);
	    }
	    while(!q.empty()){
	        int t=q.front();
	        q.pop();
	        ans.push_back(t);//we took
	        for(auto i:adj[t]){
	            indegree[i]-=1;
	            if(indegree[i]==0)//if after removal of one indegree we get 0 for it tab apan use bhi le lenge
	                q.push(i);
	        }
	    } 
	    return ans;
	}
