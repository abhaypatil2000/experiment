struct UnionFind
{
	vector<int> v; // to store the parent of current node. i.e, v[i] is the parent of i
	vector<int> rank; // stores the rank of each node // rank = number of nodes below the current node
	UnionFind(int N) // constructor to initialise N number of nodes, each with parent as itself and rank = 1. i.e., all nodes are disjoint
	{
		v.resize(N);
		rank.resize(N, 1); // rank = 1 for all nodes
		int i;
		for (i = 0; i < N; i++)
			v[i] = i; // parent[i] = i // parent of itself
	}
	void Union(int a, int b)
	{
		int x, y;
		x = Find(a);
		y = Find(b);
		if (x == y)
			return;
		if (rank[x] > rank[y]) // if merging two disjoint sets, make the parent of bigger set as the ultimate parent of their union
		{
			v[y] = x;
			rank[x] += rank[y];
		}
		else
		{
			v[x] = y;
			rank[y] += rank[x];
		}
		//v[a] = v[b];
	}
	int Find(int x)
	{
		if (v[x] == x)
			return x;
		return (v[x] = Find(v[x])); // path compression step.
		// return Find(v[x]) // without path compression
	}
};
