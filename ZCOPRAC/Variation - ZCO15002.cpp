#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, K, i = 0, j = 1, s = 0;
	cin >> n >> K;
	long long a[n];
	for (long long k = 0; k < n; k++){ cin >> a[k]; }
	sort(a, a + n);

	while (j < n && i < n) {
		if (a[j] - a[i] >= K) {
			s += n - j;
			i++;
		}
		else { j++; }
	}
	cout << s;
}
