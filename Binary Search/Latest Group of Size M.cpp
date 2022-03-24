/*
Given an array arr that represents a permutation of numbers from 1 to n.

You have a binary string of size n that initially has all its bits set to zero. At each step i 
(assuming both the binary string and arr are 1-indexed) from 1 to n, the bit at position arr[i] is set to 1.

You are also given an integer m. Find the latest step at which there exists a group of ones of length m.
A group of ones is a contiguous substring of 1's such that it cannot be extended in either direction.

Return the latest step at which there exists a group of ones of length exactly m. If no such group exists, return -1.

Input: arr = [3,5,1,2,4], m = 1
Output: 4
Explanation: 
Step 1: "00100", groups: ["1"]
Step 2: "00101", groups: ["1", "1"]
Step 3: "10101", groups: ["1", "1", "1"]
Step 4: "11101", groups: ["111", "1"]
Step 5: "11111", groups: ["11111"]
The latest step at which there exists a group of size 1 is step 4.
*/
class Solution {
public:
    int findLatestStep(vector<int>& a, int m) {
        if(a.size()==m) return a.size();
        set<pair<int,int>> s;
        s.insert({1,a.size()});
        for(int i=a.size()-1;i>=0;i--){
            if(s.empty())
                break;
            auto pt=s.upper_bound({a[i],INT_MAX});
            pt--;
            int left=pt->first;
            int right=pt->second;
            if(a[i]-left==m || right-a[i]==m )
                return i;
            if(a[i]>right || a[i] < left) continue;
            s.erase(pt);
            if(a[i]-left>0)
                s.insert({left,a[i]-1});
            if(right-a[i]>0)
                s.insert({a[i]+1,right});
        }
        return -1;
    }
};
