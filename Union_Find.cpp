struct UnionFind
{
	vector<int> v;
	vector<int> rank;
	UnionFind(int N)
	{
		v.resize(N + 5);
		rank.resize(N + 5, 1);
		int i;
		for (i = 0; i < N; i++)
			v[i] = i;
	}
	void Union(int a, int b)
	{
		int x, y;
		x = Find(a);
		y = Find(b);
		if (x == y)
			return;
		if (rank[x] > rank[y])
		{
			v[b] = x;
			rank[x]++;
		}
		else
		{
			v[a] = y;
			rank[y] = rank[y] + rank[x];
		}
		//v[a] = v[b];
	}
	int Find(int x)
	{
		if (v[x] == x)
			return x;
		return (v[x] = Find(v[x]));
	}
};
