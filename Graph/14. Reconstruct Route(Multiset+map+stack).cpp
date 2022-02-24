//ans=> https://leetcode.com/problems/reconstruct-itinerary/discuss/631629/C%2B%2B-Solution-with-detailed-explanation
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> adj;//map for O(1) search, multiset as it automatically sets minimum first so lexical order maintained but if we had a case where we
        int n=tickets.size();                      //move to lexical smallest ut it has no path ahead then?? for this we use stack which stores all traversal till last and then if no adjacent we pop elements out
        for(int i=0;i<n;i++){
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        vector<string> ans;
        stack<string> s;
        s.push("JFK");// 1.START
        while(!s.empty()){
            string t=s.top();
            if(adj[t].size()==0){ //no adjacent elment then just push that in ans and pop from stack
                ans.push_back(t);
                s.pop();    
            }
            else{//if there are elements then we need to travel them all. So, we first go to lexically smallest and push it in stack and then erase it fom list.If,it had no further hen pop from stack
                auto n=adj[t].begin();
                s.push(*n);
                adj[t].erase(n);
            }
        }
        reverse(ans.begin(),ans.end());//reverse as the ans. we got is frrom dest to src 
        return ans;
    }
};
