/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n))

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/
# 1. Take i=0 and j=0 (start of two arrays) and count till kth element

# 2. Find kth element of two arrays if n => even and if n => odd then ans= [n/2 + (n/2)+1] / 2.0
class Solution {
public:
     // MAIN FUNCTION
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        
        if( (n+m)%2 ) return kthElement(arr1, arr2, n, m, (n+m+1)/2);
        
        int a = kthElement(arr1, arr2, n, m, (n+m)/2);
        int b = kthElement(arr1, arr2, n, m, (n+m)/2 + 1);

        return (a + b) / 2.0 ;
    }
  
    int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k)
    {
        // most important thing, initialization of low, high
        int low = max(0, k-m), high = min( n, k );
        int indx, indx2;
        while(low <= high)
        {
            
            int mid = low + (high - low) / 2;
            int x = mid;
            int y = k - x;  // x + y == k

            int A = ( x==0 ) ? INT_MIN : arr1[x-1];
            int B = ( y==0 ) ? INT_MIN : arr2[y-1];
  
            int C = ( x+1 <= n) ? arr1[x] : INT_MAX ;
            int D = ( y+1 <= m) ? arr2[y] : INT_MAX ;

			// Array visualization
            // ---------A     C---------
            // ---------B     D---------
            
            if( (A<=D) && (B<=C) )
            {
                indx = mid;
                indx2 = k - mid;
                break;
            }
            else if( A > D )
                high = mid - 1;
            else 
                low = mid + 1;
        }

        int ans;
        if(indx <= n)
        {
            int a = (indx > 0) ? arr1[indx - 1] : INT_MIN;
            int b = (indx2 > 0) ? arr2[ indx2 - 1] : INT_MIN;
            return max(a, b);
        }
        return arr2[ indx2 - 1];
    }
};
