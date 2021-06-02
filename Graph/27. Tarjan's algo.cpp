//Does the same thing as floyd warshall bbut all it does is one dfs => O(V+E) ,whereas floyd will take 2 DFS and 1 reversal of list (changing node dir) => O(3*(V+E))
class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    void dfs(vector<vector<int>> &ans,vector<int> &disc,vector<int> &low,vector<bool> &inst,stack<int> &s,vector<int> adj[],int curr){
        static int timer=0;
        disc[curr]= low[curr]=timer;
        timer++;
        s.push(curr);
        inst[curr]=true;
        for(auto i : adj[curr]){
            if(disc[i]==-1){
                dfs(ans,disc,low,inst,s,adj,i);
              // Check if the subtree rooted with 'v' has a
             // connection to one of the ancestors of 'u'
                low[curr]=min(low[i],low[curr]);//imp
            }
             // Update low value of 'u' only of 'v' is still in stack
            // (i.e. it's a back edge, not cross edge).
            else if(inst[i]==true){
                low[curr]=min(low[curr],disc[i]);//imp
            }
        }    
        if(low[curr]==disc[curr]){
            vector<int> v;
            while(s.top()!=curr and !s.empty()){//for current scc from head 
                int t=s.top();
                inst[t]=false;
                v.push_back(t);
                s.pop();
            }
            if(!s.empty()){
            v.push_back(s.top());
            inst[s.top()]=false;
            s.pop();
            }
            sort(v.begin(),v.end());
            //reverse(v.begin(),v.end());
            ans.push_back(v);
        }
    }
    vector<vector<int>> tarjans(int v, vector<int> adj[])
    {
        //code here
        vector<int> disc(v,-1);
        vector<int> low(v,-1);
        vector<bool> inst(v,false);//to check if element is in stack
        stack<int> s;
        vector<vector<int>> ans;
        for(int i=0;i<v;i++){
            if(disc[i]==-1){
                dfs(ans,disc,low,inst,s,adj,i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
