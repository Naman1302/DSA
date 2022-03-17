/*
You are given N number of books. Every ith book has Ai number of pages.You have to allocate contiguous books to M number of students. There can be many 
ways or permutations to do so.In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, 
the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other 
permutations and print this minimum value.
Each book will be allocated to exactly one student. Each student has to be allocated at least one book.
Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order

Input:
N = 4
A[] = {12,34,67,90}
M = 2

Output: 113

Explanation:
Allocation can be done in 
following ways:{12} and {34, 67, 90} 
Maximum Pages = 191{12, 34} and {67, 90} 
Maximum Pages = 157{12, 34, 67} and {90} 
Maximum Pages =113. Therefore, the minimum 
of these cases is 113, which is selected 
as the output.
*/
# 1. N^2 approach har se kar tak ke liye sum calculate karlo.

# 2. BINARY SEARCH over 'search space' created

class Solution 
{
    public:
    bool canalloc(int a[],int n,int m,int students){ //To check if allocation to students is possible
        int s=1,page=0;//pages alloted
        /*initially ek bachhe ko hi mmil rhi h agar limit ke upar jaata h tab bachha++*/
        for(int i=0;i<n;i++){
            if(page+a[i]>m){
                s++;
                page=a[i];
                if(page>m) return false;
            }
            else{
                page+=a[i];
            }
            if(s>students) return false;
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
         if(m>n) return -1;
        /*
        Search Space: toh min toh apan min_ele(a) books de sakte h
        aur max total of saari books pages.
        */
        int l,h,sum=0,res=-1;//res stores ans. at eaach step
        for(int i=0;i<n;i++){
            sum+=a[i];
            l=min(l,a[i]);
        }
        h=sum;
        while(l<=h){//Binary search
            int mid=l+((h-l)/2);
            if(canalloc(a,n,mid,m)){ //if canalloc at mid being max. no. of pages allocated
                //save the mid   
                res=mid;
              //we will now serch in left part cause mid se bade won't give answer desired
                h=mid-1;
            }
            else{
                l=mid+1; //agar mid se bhi na bna toh mid se chote se bhi nhi banega.
            }
        }
        return res==-1?-1:res;
    }
};
