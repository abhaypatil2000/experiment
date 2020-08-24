#include <bits/stdc++.h>

using namespace std;
// #define int long long // remember to make constants use the LL suffix
// int mox = 1e9 + 7;

int32_t main()
{
#ifdef LOCAL_ABHAY
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t, n, i, j, k, m, q;
	t = 1;
	cin >> t;
	while (t--)
	{
		cin >> n;
		m = n;
		cin >> m;
		vector<int> v(n);
		for (auto &x : v)
			cin >> x;
		vector<int> a(n);
		for (auto &x : a)
			cin >> x;
		vector<int> b(m);
		for (auto &x : b)
			cin >> x;
	}
}
