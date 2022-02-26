//https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution {
public:
    int parent[1001];
    int rank[1001]={1};
    
    //Personal Comparator	
    
    static bool comp(vector<int> a,vector<int> b){
        return a[2]<b[2];
    }
	
    //===================

    //Finding parent of given node
    
    int find_p(int v){
        if(parent[v]==-1)
            return v;
        else
            return parent[v]=find_p(parent[v]);
    }
	
    //============================	
    
    //======" UNION_OP "==========	
    
    void jod(int a,int b){
        if(rank[a]>rank[b]){
            parent[b]=a;
        }
        else if(rank[b]>rank[a]){
            parent[a]=b;
        }
        else{
            parent[a]=b;
            rank[b]++;
        }
    }
	
    //============================	
    int minCostConnectPoints(vector<vector<int>>& a) {
        int sum=0;
        memset(parent,-1,sizeof(parent));
        vector<vector<int>> g;
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                int dist=abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]);
                g.push_back({i,j,dist});
            }
        }
        sort(g.begin(),g.end(),comp);
        int i=0,j=0;
        while(i<a.size() && j< g.size()){
            int from_p=find_p(g[j][0]);
            int dest_p=find_p(g[j][1]);
            if(from_p==dest_p){
                j++;
                continue;
            }
            jod(from_p,dest_p);
            sum+=g[j][2];
            i++;
        }
        return sum;
    }
};

//===================" End of Question "=====================


//===================== " GFG CODE " ========================
#include<bits/stdc++.h>
using namespace std;

struct node {
	int parent;
	int rank;
};
struct Edge {
	int src;
	int dst;
	int wt;
};

vector<node> dsuf;
vector<Edge> mst;
//FIND operation
int find(int v)
{
	if(dsuf[v].parent==-1)
		return v;
	return dsuf[v].parent=find(dsuf[v].parent);	//Path Compression
}

void union_op(int fromP,int toP)
{
	//fromP = find(fromP);
	//toP = find(toP);

	//UNION by RANK
	if(dsuf[fromP].rank > dsuf[toP].rank)	//fromP has higher rank
		dsuf[toP].parent = fromP;
	else if(dsuf[fromP].rank < dsuf[toP].rank)	//toP has higher rank
		dsuf[fromP].parent = toP;
	else
	{
		//Both have same rank and so anyone can be made as parent
		dsuf[fromP].parent = toP;
		dsuf[toP].rank +=1;		//Increase rank of parent
	}
}

bool comparator(Edge a,Edge b)
{
	return a.wt < b.wt;
}
/*
void printEdgeList(vector<Edge>& edge_List)
{
	for(auto p: edge_List)
		cout<<"src: "<<p.src<<"  dst: "<<p.dst<<"  wt: "<<p.wt<<"\n";
	cout<<"============================================================\n";
}
*/
void Kruskals(vector<Edge>& edge_List,int V,int E)
{
	//cout<<"edge_List before sort\n";
	//printEdgeList(edge_List);
	sort(edge_List.begin(),edge_List.end(),comparator);
	//cout<<"edge_List after sort\n";
	//printEdgeList(edge_List);

	int i=0,j=0;
	while(i<V-1 && j<E)
	{
		int fromP = find(edge_List[j].src);	//FIND absolute parent of subset
		int toP = find(edge_List[j].dst);
		
		if(fromP == toP)
		{	++j;	continue;	}

		//UNION operation
		union_op(fromP,toP);	//UNION of 2 sets
		mst.push_back(edge_List[j]);
		++i;
	}
}
//Display the formed MST
void printMST(vector<Edge>& mst)
{
	cout<<"MST formed is\n";
	for(auto p: mst)
		cout<<"src: "<<p.src<<"  dst: "<<p.dst<<"  wt: "<<p.wt<<"\n";
}

int main()
{
	int E;	//No of edges
	int V;	//No of vertices (0 to V-1)
	cin>>E>>V;

	dsuf.resize(V);	//Mark all vertices as separate subsets with only 1 element
	for(int i=0;i<V;++i)	//Mark all nodes as independent set
	{
		dsuf[i].parent=-1;
		dsuf[i].rank=0;
	}

	vector<Edge> edge_List;	//Adjacency list
	Edge temp;
	for(int i=0;i<E;++i)
	{
		int from,to,wt;
		cin>>from>>to>>wt;
		temp.src = from;
		temp.dst = to;
		temp.wt = wt;
		edge_List.push_back(temp);
	}

	Kruskals(edge_List,V,E);
	printMST(mst);
	
	return 0;
}

//TIME COMPLEXITY: O(ElogE + ElogV)
//ElogE for sorting E edges in edge_list
//ElogV for applying FIND & UNION operations on E edges having V vertices
