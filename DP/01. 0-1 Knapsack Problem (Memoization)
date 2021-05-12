int dp[1002][1002];


class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSacks(int w,int wt[],int val[],int n){
        if(n==0||w==0)
            return 0;
        if(dp[n][w]!=-1)
            return dp[n][w];
        if(wt[n-1]<=w){
            return dp[n][w]=max(val[n-1]+knapSacks(w-wt[n-1],wt,val,n-1),knapSacks(w,wt,val,n-1));
        }
        else if(wt[n-1]>w){
            return dp[n][w]=knapSacks(w,wt,val,n-1);
        }
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        memset(dp,-1,sizeof(dp));
        return knapSacks(w,wt,val,n);
    }
};
