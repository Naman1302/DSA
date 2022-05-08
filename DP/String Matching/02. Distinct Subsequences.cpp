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
//1-D Optimisation
class Solution {
public:
    int minDistance(string s1, string s2) {
        //vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
        
        int n=s1.length(),m=s2.length();
        
        vector<int> prev(m+1,0),curr(m+1,0);
        
        /*for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }*/
        
        for(int j=0;j<=m;j++){
            prev[j]=j;
        }
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                    curr[j]=prev[j-1];
                else
                    curr[j]=min(1+prev[j-1],min(1+prev[j],1+curr[j-1]));
            }
            prev=curr;
        }
        return prev[m];
    }
};
