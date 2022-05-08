//Ques => https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1/#

//RECURSIVE =>

class Solution{
  public:	
    void solve(string s,unordered_set<string> &m,string t){
        if(s.length()==0)
            m.insert(t);
        if(m.find(t)!=m.end())
            return;
        string op1=t,op2=t;
        op1.push_back(s[0]);
        s.erase(s.begin()+0);
        solve(s,m,op1);
        solve(s,m,op2);
        return;
    }
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    unordered_set<string> m;
	    solve(s,m,"");
	    return m.size()%1000000007;
	}
};

//================

//TOP-DOWN =>

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    unordered_map<char,int> m;
	    int dp[s.length()+1];
	    dp[0]=1;
	    for(int i=1;i<=s.length();i++){
         // Number of subsequences with substring
         // str[0..i-1]
	        dp[i]=(2*dp[i-1])%1000000007; //all possible combinations
	        char c=s[i-1];
        // If current character has appeared
        // before, then remove all subsequences
        // ending with previous occurrence.
	        if(m.find(c)!=m.end()){//if repeating character
	            int j=m[c];
	            dp[i]=(dp[i]-dp[j-1])%1000000007;
	        }
	        if(dp[i]<0)//if it gets negative
	            dp[i]+=1000000007;
	        
	        m[c]=i%1000000007; // Mark occurrence of current character
	    }
	    return dp[s.length()]%1000000007;
	} 
};

//=====================================
