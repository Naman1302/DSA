/*
   Here approach used is Dfs+Pruning(Though Slowest of em all but simplest)
                               |-> when we get answer from one route and other one is not suitble so, we reject that route
*/
class Solution {
public:
    void solve(vector<pair<int,int>> adj[],vector<bool> &vis,int &fare,int cost,int src,int dest,int k){
        if(k<-1) //yahaan k jo h woh do src and dest ke beech ke nodes h for eg:-    0   ->  1  ->2
                 //                                                               src,k=1   k=0   dest,k=-1
            return;
        if(src==dest){
            fare=min(cost,fare);//
            return;
        }
        vis[src]=true;//pehle apan us node route bna ke dekhte h if it works
        for(auto i:adj[src]){
            if(!vis[i.first] and cost+i.second<fare){
                solve(adj,vis,fare,cost+i.second,i.first,dest,k-1);
            }
        }
        vis[src]=false;//if not then usko unvisited kar diye
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<bool> vis(n+1,false);
        int fare=INT_MAX;
        solve(adj,vis,fare,0,src,dst,k);
        return fare==INT_MAX ? -1 :fare;
    }
};
//Bfs+heap
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
       
//      this is adjancy list.
        map<int, vector<pair<int, int>> > mp;
        for(auto fl : flights){
            mp[fl[0]].push_back({fl[1], fl[2]});
        }
       
//      <cost, nodeId, number of stop>
        priority_queue<array<int, 3> , vector<array<int, 3>>, greater<array<int,3>>> pq;
        pq.push({0, src, 0});
       
        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();
            int cost = tp[0];
            int nodeID = tp[1];
            int stop = tp[2];
            if(nodeID == dst) return cost;
            if(stop > K) continue;
            for(auto p : mp[nodeID]){
                int v = p.first;
                int weight = p.second;
                pq.push({cost+weight, v, stop+1});
            }
        }
     
        return -1;
    }
};
