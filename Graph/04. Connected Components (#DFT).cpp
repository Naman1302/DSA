#QUES  => https://code.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> gr[],vector<bool> &vis,int cur){
    vis[cur]=true;
    for(auto k:gr[cur]){
        
        if(!vis[k]){
            dfs(gr,vis,k);
        }
    }
}
int main(){
        int n,e;
        cin>>n>>e;
        vector<int> gr[n+1];
        for(int i=1;i<=e;i++){
            int x,y;
            cin>>x>>y;
            gr[x].push_back(y);
            gr[y].push_back(x);
        }
        vector<bool> vis(n+1,false);
        int count=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(gr,vis,i);
                count++;
            }
        }
        cout<<count<<endl;
}
