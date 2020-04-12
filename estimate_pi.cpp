#include <bits/stdc++.h>

using namespace std;

int main()
{
	srand(time(NULL));
	double in = 0, out = 0;
	double ans;
	double x, y;
	for (long long int i = 0; i < 100000000000000; i++)
	{
		x = rand();
		x = x / RAND_MAX;
		y = rand();
		y = y / RAND_MAX;
		//y = rand() / RAND_MAX;
		if (x * x + y * y > 1)
			out++;
		else
			in++;
	}
	ans = 4 * in / (in + out);
	cout << ans;
}
