#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],vector<int> &dist,vector<int> &pred,int src,int end){
    vector<bool> vis(dist.size(),false);
    queue<int> q;
    q.push(src);
    vis[src]=true;
    dist[src]=0;
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!vis[i]){
                vis[i]=true;
                dist[i]=dist[node]+1;
                pred[i]=node;
                q.push(i);
                
                if(i==end)
                    return;
            }
        }
    }
}
int main() {
	int n,e,start,end;
	cin>>n>>e>>start>>end;
	vector<int> adj[n+1];
	for(int i=0;i<e;i++){
	    int x,y;
	    cin>>x>>y;
	    adj[x].push_back(y);
	    adj[y].push_back(x);
	}
	vector<int> dist(n+1,INT_MAX),pred(n+1,-1);
	bfs(adj,dist,pred,start,end);
	cout<<dist[end];
	return 0;
}
