class Solution {
public:
    unordered_map<string,bool> mp;
    bool isScramble(string a, string b) {
        if(a.compare(b)==0)
            return true;
        if(a.length()<=1)
            return false;
        string key=a+"_"+b;
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        int n=a.length();
        bool flag=false;
        for(int i=1;i<=n-1;i++){
            //CASE 1 - no swap
            bool c1=isScramble(a.substr(0,i),b.substr(0,i))&&isScramble(a.substr(i,n-i),b.substr(i,n-i));
            //CASE 2 - Swap
            bool c2=isScramble(a.substr(0,i),b.substr(n-i,i))&&isScramble(a.substr(i),b.substr(0,n-i));
            if(c1||c2)
            {flag=true; break;}
        }
        return mp[key]=flag;
    }
};
