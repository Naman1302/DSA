//============TOP-DOWN=============

int dp[202][202];
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int n,int k){
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(i==1)    
                    dp[1][j]=j;
                if(j==0||j==1&&i>1)
                    dp[i][j]=j;
            }
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=k;j++){
                dp[i][j]=INT_MAX;
                for(int p=1;p<=j;p++){
                    dp[i][j]=min(dp[i][j],1+max(dp[i-1][p-1],dp[i][j-p]));
                }
            }
        }
        return dp[n][k];
       
    }
    int eggDrop(int e, int f)
    {
        return solve(e,f);
    }    
};

//===========MEMOZISED_OPTIMISED=============

int dp[202][202];
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int n,int k){
        if(n==1)
            return k;
        if(k==0||k==1)
            return k;
        if(dp[n][k]!=-1)
            return dp[n][k];
        int ans=INT_MAX;    
        for(int i=1;i<=k;i++){
            int below_k,above_k;
            if(dp[n-1][i-1]!=-1)
                below_k=dp[n-1][k-1];
            else
                below_k=eggDrop(n-1,i-1);
                
            if(dp[n][k-i]!=-1)
                above_k=dp[n][k-1];
            else
                above_k=eggDrop(n,k-i);
                
            int temp_ans=1+max(below_k,above_k);
            ans=min(ans,temp_ans);        
        }    
        return dp[n][k]=ans;
    }
    int eggDrop(int n, int k)
    {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};
