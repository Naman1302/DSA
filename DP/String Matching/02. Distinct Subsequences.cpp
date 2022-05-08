class Solution {
public:
    /*
    int solve(string s,string t,int i,int j,vector<vector<int>> &dp){
        if(j==0)
            return 1;
        if(i==0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i-1]==t[j-1])
            return dp[i][j]=solve(s,t,i-1,j-1,dp)+solve(s,t,i-1,j,dp);  //agar match kiya then we can either take it or leave it
        return dp[i][j]=solve(s,t,i-1,j,dp);
    }
    */
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<double> prev(m+1);
        vector<double> curr(m+1);
        prev[0]=curr[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    curr[j]=prev[j-1]+prev[j];
                else
                    curr[j]=prev[j]; 
            }
            prev=curr;
        }
        return (int)curr[m];
        //return solve(s,t,s.length()-1,t.length()-1,dp);
    }
};
