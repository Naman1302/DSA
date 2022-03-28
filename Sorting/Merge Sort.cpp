class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int i=l,j=m+1,k=0;
         int size=r-l+1;
         int *save;
         save=new int[size];
        while(i<=m && j<=r){//until one vector finds its limit.
            if(arr[i]<arr[j]){//first left < first right
                save[k]=arr[i];
                i++;
            }
            else{
                save[k]=arr[j];
                j++;
            }
            k++;
        }
        if(i>m){//left vector passed his limit?
            while(j<=r){  //put the rest of right vector on "save";
                save[k]=arr[j];
                j++;
                k++;
            }
        }
        if(j>r){//right vector passed his limit?
            while(i<=m){//put the rest of left vector on "save";
                save[k]=arr[i];
                i++;
                k++;
            }
        }
        for(k=0;k<size;k++){//copy "save" into "arr" in the correct position.
            arr[l]=save[k];//[l] ->relative position.
            l++;
        }
        delete [] save;
         
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {  
        //code here
        if(l<r){
            int m=l+(r-l)/2;
            mergeSort(arr,l,m);//left
            mergeSort(arr,m+1,r);//right
            merge(arr,l,m,r);//merge left and right.
        }
    }
};
