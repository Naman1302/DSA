//Dijkstra in directed graph
//https://leetcode.com/problems/network-delay-time/
class Solution {
public:
    int min_v(vector<int> key,vector<bool> s){
        int v=-1,m=INT_MAX;
        for(int i=0;i<key.size();i++){
            if(s[i]==false && key[i]<m){
                v=i;
                m=key[i];
            }
        }
        return v;
    }
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        vector<pair<int,int>> g[n+1];
        for(int i=0;i<t.size();i++){
            g[t[i][0]].push_back({t[i][1],t[i][2]});
        }
        if(g[k].size()==0) return -1;
        
        vector<int> key(n+1,INT_MAX);
        vector<bool> s(n+1,false);
        key[k]=0;
        for(int i=0;i<n-1;i++){
            int v=min_v(key,s);
            s[v]=true;
            for(auto x:g[v]){
                if(s[x.first]==false && x.second+key[v]<key[x.first]){
                    key[x.first]=x.second+key[v];
                }
            }
        }
        int m=0;
        for(int i=1;i<n+1;i++){
            m=max(m,key[i]);
        }
        return m==INT_MAX?-1:m;
    }
};
