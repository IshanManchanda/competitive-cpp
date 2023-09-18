#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	unsigned long long n, K, s = 0;
	cin >> n >> K;
	long long left = 0, right = n - 1;
	long long a[n];
	for (long long k = 0; k < n; k++){ cin >> a[k]; }
	sort(a, a + n);

	while (left < right) {
		if (a[left] + a[right] < K) {
			s += right - left;
			left++;
		}
		else { right--; }
	}
	cout << s;
}
