// Ques 1 => https://practice.geeksforgeeks.org/problems/rod-cutting0840/1/#
class Solution{
  public:
    /* *RECURSION*
    int solve(int a[],int i,int l){
        if(i==0){
            return (l)*a[0];
        }
        
        int not_take=0+solve(a,i-1,l);
        
        int rodl=i+1;
        
        int take=INT_MIN;
        
        if(l>=rodl){
            take=a[i]+solve(a,i,l-rodl);
        }
        
        return max(take,not_take);
    }
    */
    int cutRod(int a[], int n) {
        //code here
        int dp[n][n+1];// as length is n and index is till n-1 :)
        
        for(int i=0;i<=n;i++){
            dp[0][i]=i*a[0];    //base case
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                
                int not_take=0+dp[i-1][j];
                
                int rodl=i+1;
                
                int take=INT_MIN;
                if(j>=rodl){
                    take=a[i]+dp[i][j-rodl];
                }
                dp[i][j]=max(take, not_take);
            }
        }
        return dp[n-1][n];
    }
};

// Ques 2. => https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#

class Solution
{
    public:
    int solve(vector<int> &a,int sum,int n){
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0)
                    dp[i][j]=INT_MIN; // as we are maximising the numer of rods so if there isn't any then we go for INT_MIN
                else if(j==0)
                    dp[i][j]=0;
                else{
                    if(a[i-1]<=j)
                        dp[i][j]=max(1+dp[i][j-a[i-1]] , dp[i-1][j]); //here we do +1 as each cut would increse th count of segments and if we don't choose it then no increase in segment
                    else
                        dp[i][j]=dp[i-1][j];
                }        
            }
        }
        return dp[n][sum]<0 ? 0 : dp[n][sum];
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> a={x,y,z};
        return solve(a,n,a.size());
    }
};
