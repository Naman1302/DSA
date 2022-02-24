/*
  https://leetcode.com/problems/cheapest-flights-within-k-stops/discuss/626208/Detailed-C%2B%2B-Standard-Approaches-DP-Approach-(DFS-with-memoization)-BFS
  Here approach used is Dfs+Pruning(Though Slowest of em all but simplest)
                               |-> when we get answer from one route and other one is not suitble so, we reject that route
*/
class Solution {
public:
    /*void solve(vector<pair<int,int>> adj[],vector<bool> &vis,int &fare,int cost,int src,int dest,int k){
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
    TLE MILA
    */
    int dp[10001][101];
    int solve(vector<pair<int,int>> g[],int s,int e,int k){
        if(s==e) return 0;
        if(k<=-1) return INT_MAX;
        if(dp[s][k]!=-1) return dp[s][k];
        int ans=INT_MAX;
        for(auto x:g[s]){
            int temp=solve(g,x.first,e,k-1);
            if(temp!=INT_MAX)
                ans=min(ans,x.second+temp);    
        }
        return dp[s][k]=ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<pair<int,int>> g[n];
        for(auto x:f){
            g[x[0]].push_back({x[1],x[2]});
        }
        memset(dp,-1,sizeof(dp));
        int ans=solve(g,src,dst,k);
        return ans==INT_MAX?-1:ans;
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
