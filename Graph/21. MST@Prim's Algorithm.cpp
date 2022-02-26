//Minimum cost to add all cities
//  https://leetcode.com/problems/min-cost-to-connect-all-points

class Solution {
public:
    //=========Finding minimum 'V'=======
    int min_v(vector<int> key,vector<bool> mst){
        int m=INT_MAX,m_i=0;
        for(int i=0;i<key.size();i++){
            if(key[i]<m && !mst[i]){
                m_i=i;
                m=key[i];
            }
        }
        return m_i;
    }
    //====================================
    int minCostConnectPoints(vector<vector<int>>& a) {
        vector<pair<int,int>> g[a.size()];
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                int dist=abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]);
                g[i].push_back({j,dist});
                g[j].push_back({i,dist});
            }
        }
        //only updated if value is less
        vector<int> key(a.size(),INT_MAX);
        key[0]=0;
        //last filled is mst
        vector<bool> mst(a.size(),false);
        for(int i=0;i<a.size()-1/* kyunki last wale pe process karne ki jarurat nhi*/;i++){
            int mini_v = min_v(key,mst);
            //found minimum vertex
            mst[mini_v]=true;
            for(auto i:g[mini_v]){
                if(mst[i.first]==false && key[i.first]>i.second ){
                    key[i.first]=i.second;
                }
            }
        }
        int sum=0;
        for(int i=1;i<key.size();i++){
            sum+=key[i];
        }
        return sum;
    }
};

//Adjacency List + Priority Queue
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(auto i:adj[x])
        {
            y = i.second;
            if(marked[y] == false)
                Q.push(i);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}

// Adjacency Matrix+arrays(GFG)
int min_ver(vector<int> &value,vector<bool> &mst){
        int min=INT_MAX,index;
        for(int i=0;i<value.size();i++){
            if(mst[i]==false and value[i]<min){
                min=value[i];
                index=i;
            }
        }
        return index;
    }
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        int parent[v];
        vector<bool> mst(v,false);
        vector<int> value(v,INT_MAX);
        
        parent[0]=-1;
        value[0]=0;
        
        int sum=0;
        
        for(int i=0;i<v-1;i++){
            int u=min_ver(value,mst);
            mst[u]=true;
            for(auto j: adj[u]){
                vector<int> V=j;
                int w=V[1],node=V[0];
                if(w and value[node]>w && mst[node]==false){
                    value[node]=w;
                    parent[node]=u;
                }
            }
        }
        for(int i=1;i<v;i++){
            sum+=value[i];
        }
        return sum;
    }
