
// A recursive function that find articulation points using DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps tract of visited vertices
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> earliest visited vertex (the vertex with minimum
//			 discovery time) that can be reached from subtree
//			 rooted with current vertex
// parent[] --> Stores parent vertices in DFS tree
// ap[] --> Store articulation points
void APUtil(vector<int> adj[],int u, bool visited[], int disc[],
									int low[], int parent[], bool ap[])
{
	// A static variable is used for simplicity, we can avoid use of static
	// variable by passing a pointer.
	static int time = 0;

	// Count of children in DFS Tree
	int children = 0;

	// Mark the current node as visited
	visited[u] = true;

	// Initialize discovery time and low value
	disc[u] = low[u] = ++time;

	// Go through all vertices aadjacent to this
	
	for (auto v:adj[u])
	{
		// If v is not visited yet, then make it a child of u
		// in DFS tree and recur for it
		if (!visited[v])
		{
			children++;
			parent[v] = u;
			APUtil(adj,v, visited, disc, low, parent, ap);

			// Check if the subtree rooted with v has a connection to
			// one of the ancestors of u
			low[u] = min(low[u], low[v]);

			// u is an articulation point in following cases

			// (1) u is root of DFS tree and has two or more chilren.
			if (parent[u] == NIL && children > 1)
			ap[u] = true;

			// (2) If u is not root and low value of one of its child is more
			// than discovery value of u.
			if (parent[u] != NIL && low[v] >= disc[u])
			ap[u] = true;
		}

		// Update low value of u for parent function calls.
		else if (v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

// The function to do DFS traversal. It uses recursive function APUtil()
void :AP(vector<int> adj[])
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	int *disc = new int[V];
	int *low = new int[V];
	int *parent = new int[V];
	bool *ap = new bool[V]; // To store articulation points

	// Initialize parent and visited, and ap(articulation point) arrays
	for (int i = 0; i < V; i++)
	{
		parent[i] = NIL;
		visited[i] = false;
		ap[i] = false;
	}

	// Call the recursive helper function to find articulation points
	// in DFS tree rooted with vertex 'i'
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			APUtil(adj,i, visited, disc, low, parent, ap);

	// Now ap[] contains articulation points, print them
	for (int i = 0; i < V; i++)
		if (ap[i] == true)
			cout << i << " ";
}
