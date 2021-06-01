void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1)
	                matrix[i][j]=101;
	        }
	    }
	    for(int k=0;k<n;k++){//for every vertex to be treated as an intermediate vertex 
	        for(int i=0;i<n;i++){//for taken intermediate we need starting vertex
	            for(int j=0;j<n;j++){//for destination vertex
	                    if((matrix[k][j]!=101 and matrix[i][k]!=101) and matrix[i][j]>(matrix[i][k]+matrix[k][j]) ){
	                        matrix[i][j]=matrix[i][k]+matrix[k][j];
	                    }
	            }
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==101)
	                matrix[i][j]=-1;
	        }
	    }
	    return;
	}
