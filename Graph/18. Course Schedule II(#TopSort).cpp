class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        int cnt=0;
        vector<int> indegree(n,0);
        vector<int> adj[n];
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<prerequisites.size();i++){
                indegree[prerequisites[i][0]]++;
                adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(auto x:adj[curr]){
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);
            }
            cnt++;
        }
        if(cnt!=n)//if there is a cycle;
            return {};
        return ans;
    }
};
