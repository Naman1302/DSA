/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
# 1. Brute Force

# 2. Take ith element and do Two_sum by map

# 3. Take ith element and do Binary Search in remaining part
> Do Sort

class Solution {
public:
    int threeSumClosest(vector<int>& a, int t) {
        int n=a.size(),ans=INT_MAX,diff=INT_MAX;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=a[i]+a[j]+a[k];
                if(sum>t){
                    k--;
                }
                else if(sum<t){
                    j++;
                }
                else{
                    return t;
                }
                ans=abs(sum-t)<diff?sum:ans;
                diff=min(diff,abs(sum-t));
            }
        }
        return ans;
    }
};
