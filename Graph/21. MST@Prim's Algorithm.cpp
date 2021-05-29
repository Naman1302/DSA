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
