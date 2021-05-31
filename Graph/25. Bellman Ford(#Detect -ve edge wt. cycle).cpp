	int isNegativeWeightCycle(int n, vector<vector<int>>e){
	    // Code here
	    vector<int> value(n,INT_MAX);
	    value[0]=0;
	    bool update;
	    for(int i=0;i<n-1;i++){
	        update=false; 
	        for(int j=0;j<e.size();j++){
	            int s=e[j][0],d=e[j][1],w=e[j][2];
	            if(value[s]!=INT_MAX and value[s]+w<value[d]){
	                value[d]=value[s]+w;
	                update=true;//to check if we had updated anything
	            }
	        }
	        if(update==false) break;//if no update that means there might be no cycle
	    }
    //we need to check one more time if there is a change in values or not cause if there is a -ve edge wt. cycle then it will update values
	    for(int i=0;i<e.size();i++){
	        int s=e[i][0],d=e[i][1],w=e[i][2];
	        if(value[s]!=INT_MAX and value[s]+w<value[d])
	                return 1;//if yes then return 1 at that moment
	    }
	    return 0;//else
	}
