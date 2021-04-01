#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q;
	cin >> n >> m;
	vector a[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	make_heap(a.begin(), a.end());

	int it = 0;
	while (m--) {
		cin >> q;
		while (it < q) {

		}

	}
	return 0;
}
