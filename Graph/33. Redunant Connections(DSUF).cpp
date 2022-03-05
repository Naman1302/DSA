//https://leetcode.com/problems/redundant-connection
class Solution {
public:
    int parent[1001];
    int rank[1001]={1};
    
    int find(int u){
        return parent[u]==-1?u:parent[u]=find(parent[u]);
    }
    void jod(int a,int b){
        if(rank[a]>rank[b]){
            parent[b]=a;
        }
        else if(rank[b]>rank[a]){
            parent[a]=b;
        }
        else{
            parent[b]=a;
            rank[a]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        memset(parent,-1,sizeof(parent));
        vector<int> a(2);
        for(auto i:e){
            int u=find(i[0]);
            int v=find(i[1]);
            if(u!=v)
                jod(u,v);
            else{
                a[0]=i[0];
                a[1]=i[1];
            }
        }
        return a;
    }
};
