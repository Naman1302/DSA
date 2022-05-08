class Solution {
public:
    /*int solve(string &s,string &t,int i,int j,vector<vector<int>> &dp){
        if(i==0)
            return j;
        if(j==0)
            return i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1])
            return dp[i][j]=solve(s,t,i-1,j-1,dp);
        
        return dp[i][j]=min(1+solve(s,t,i-1,j-1,dp),min(1+solve(s,t,i-1,j,dp),1+solve(s,t,i,j-1,dp)));
    }*/
    int minDistance(string s1, string s2) {
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
        int n=s1.length(),m=s2.length();
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(1+dp[i-1][j-1],min(1+dp[i-1][j],1+dp[i][j-1]));
            }
        }
        return dp[n][m];
    }
};
