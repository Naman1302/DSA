/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
*/

# 1. Brute Force

# 2. Take i'th element and do 2-Sum for remaining part  with unordered-map

# 3. Binary search in reamaining part
//SORT FIRST
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        // base condition
        if(n < 3)
            return {};
        //result array
        vector<vector<int>> res;
        
        // array must be sorted
        sort(arr.begin() , arr.end());
        
        // iterate through the array
        for(int i = 0; i < n; i++)
        {
            // skip the duplicates
            if(i > 0 && arr[i] == arr[i-1])
                continue;
            
            // two pointers
            int j = i+1, k = n-1;
            
            // try to decrease this window
            while(j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if(sum < 0)
                    j++;
                else if(sum > 0)
                    k--;
                else
                {
                    // got a triplet
                    res.push_back({arr[i] , arr[j] , arr[k]});
                    
                    //skip the duplicates
                    while(j < k && arr[j] == arr[j+1]) j++;
                    while(j < k && arr[k] == arr[k-1]) k--;
                    j++;
                    k--;
                }
            }
                
        }
        return res;
    }
};
