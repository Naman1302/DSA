/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. 
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.

Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
*/
//==========Brute Force==========

# Linear Search

//===============================

//======Omptimised Approach======
# BINARY SEARCH

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int k) {
        for(int i=0;i<a.size();i++){
            int l=0,h=a.size()-1;
            while(l<=h){
                int m=l+((h-l)/2);
                
                if(a[m]==k-a[i]){
                    if(m==i)
                        l=m+1;
                    else
                        return {i+1,m+1};
                }
                else if(a[m]>k-a[i]){
                    h=m-1;
                }
                else{
                    l=m+1;
                }
            }
        }
        return {};
    }
};

//===============================
