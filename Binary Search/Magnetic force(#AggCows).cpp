/*
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are 
put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls
and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls 
is maximum.
Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
Given the integer array position and the integer m. Return the required force.

Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs 
[3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
*/
# AGGRESIVE COWS

class Solution {
public:
    bool can(vector<int> a,int cows,int gap){
        int cows_now=1;//we can intitally place a cow/ball
        int last_cow=a[0];//at box on a[0]th index
        for(int i=1;i<a.size();i++){
            if(a[i]-last_cow>=gap){//if we exceed the gap then cow can be placed here so cow++
                cows_now++;
                if(cows_now==cows) return true;//if all placed then a valid value of gap
                last_cow=a[i];//else the new cow is now at a[i]th index on x-axis where a box is there
            }
        }
        return false;//if cows_placed are greater than required then not valid
    }
    int maxDistance(vector<int>& a, int k) {
        sort(a.begin(),a.end());
       int res=0;
       int l=a[1]-a[0];//min distance that can be possible 
       int h=a[a.size()-1]-a[0];//max distance that can be possible
       while(l<=h){
           int m=l+((h-l)/2);//we need to check if we can place at balls at distances >= m 
           if(can(a,k,m)){//if yes then lesser than m values will give lesser but we need max force on each which is min.
               l=m+1;//we will look into right side
               res=m;//but tore this as this can be ans
           }
           else{
               h=m-1;//if not then no higher values will give ans
           }
       }
        return res;
    }
};
