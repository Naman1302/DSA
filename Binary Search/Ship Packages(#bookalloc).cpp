/*
A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt 
(in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like 
(2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
*/
# BOOK ALLOCATON JAISA

class Solution {
public:
    bool canalloc(vector<int> &w,int d,int m){
        int din=1,load=0;
        for(int i=0;i<w.size();i++){
            if(load+w[i]>m){//if load is greater than capacity  then we need a new day
                load=w[i];
                din++;
                if(load>m) return false;//if new load is greater than what can we store then this distribution is invalid
            }
            else
                load+=w[i];
            if(din>d) return false;//agar din d se jyada toh no use
        }
        return true;//valid
    }
    int shipWithinDays(vector<int>& w, int d) {
        int l=w[0],h=0;
        
        for(int i=0;i<w.size();i++){
            l=min(l,w[i]);//we need to find min number of packages and thus max days 
            h+=w[i];//sum will give max packages and thus min days
        }
      //we need to find the min ship capacity so that packages can be transferred in d days.
        int res=-1;
        while(l<=h){
            int m=l+((h-l)/2);//if we can have capacity m ship capacity then can we get in d days?
            if(canalloc(w,d,m)){ //if yes then greater than that will give ans but we need min. 
                res=m;
                h=m-1;
            }
            else
                l=m+1;//if not then not can be for lesser than m
        }
        return res;
    }
};
