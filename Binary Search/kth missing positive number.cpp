#1. create an array and count number which are present then count for kth missing

#2. BINARY SEARCH
//a[i]-1 gives total numbers that should be behind a[i] i.e. a[i]= 4 means that 1-4 are to be present behind it
//a[i]-1-(i-0) gives the total missing numbers before a[i]
class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        if(k<a[0]) return k;
        int l=0,h=a.size();
        while(l<h){
            int m=l+((h-l)/2);
            if(a[m]-m-1<k){//if misiing numbers before m are less than k then wwe need to go right
                l=m+1;
            }
            else{//else if misiing numbers before m are greater than or equal to k
                h=m;//we need to go left
            }
        }
          //whatever the answer it lies in between l-1 and r as after last step does l=r
         //and it is equal to arr[end] - (B[end] - k + 1), where the second part is how 
        //many steps we need to make backward. Using B[end] = arr[end] - end - 1, 
       //we have end + k, we need to return.
        return l+k; // return (arr[h])-(arr[h]-h-1-k+1)=l+k;
    }
};
