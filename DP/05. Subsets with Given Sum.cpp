int Solution::solve(vector<int> &A, int B) {
    int dp[A.size()+1][B+1],N=A.size();
    
    for(int i=0;i<=N;i++){
        for(int j=0;j<=B;j++){
            if(i==0)
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;
        }
    }
     for(int i=1;i<=N;i++){
        for(int j=1;j<=B;j++){
           if(A[i-1]<=j){
                dp[i][j]=(dp[i-1][j-A[i-1]]+dp[i-1][j]);
                }
                else if(A[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                } 
        }
    }
    
    return dp[N][B];
}

//GFG QUESTION WITH ZEROES

/* 
Here extra we have to take care of zeroes also.

When the input array has any zeros: For eg: n=3, sum=0.

We can have a set here as {0,1,2}, so there'll be subsets of {} and {0} possible hence count will be 2. 

This is true for multiple other input arrays where actually count >1 for sum=0, but we initialized count=1 for all input arrays when sum=0. 

Here's a small fix I found to the issue: 

We initialize the first column of the array acc to the formula: 2 ^ (no of zeros in the array at that size).

 Hence, for eg: arr={0,0,1,0}, sum=0 

For n=0, value will be 2^0 = 1, i.e {} 

For n=1, value will be 2^1 = 2, i.e. {} and {0}

 For n=2, value will be 2^2= 4, i.e. {}, {0}, {0} and {0,0}

 For n=3, value will be 2^2 = 4, i.e. {}, {0], {0}, and {0,0}

 For n=4, value will be 2^3 = 8 i.e. {}, .............., {0,0,0} 

Reason: In the sum of subset problem, we simply needed to return whether or not a set exists for sum=0, which was always True as empty set {} was always existing. Here, we need to return count of subsets for sum=0 (for first column), which will include all possible subsets in the array which add up to 0.
*/

public:
	int count_zeros_till_index(int arr[],int i)//returns the numberof zeros in array till index i
	{
	    int count=0;
	    for(int j=0;j<=i;j++)
       {
           if(arr[j]==0)
            count++;
       }
       return count;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    long long mod=1e9+7;
	    long long dp[n+1][sum+1];
	    
        for(int i=0,j=0;j<sum+1;j++)
            dp[i][j]=0;
        for(int i=0,j=0;i<n+1;i++)
        {
            dp[i][j]=pow(2,count_zeros_till_index(arr,i));
            //A little modification that is needed from Aditya verma's Code
        }                                         
            
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                {
                    dp[i][j]=((dp[i-1][j-arr[i-1]])%mod+(dp[i-1][j])%mod)%mod;
                }
                else dp[i][j]=dp[i-1][j]%mod;
            }
        }
        return dp[n][sum];
	}
	  
};
