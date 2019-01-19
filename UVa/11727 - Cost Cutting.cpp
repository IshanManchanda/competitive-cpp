#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long t, a[3];
	cin >> t;
	for (long long i = 1; i <= t; i++) {
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		cout << "Case " << i << ": " << a[1] << endl;
	}


}
