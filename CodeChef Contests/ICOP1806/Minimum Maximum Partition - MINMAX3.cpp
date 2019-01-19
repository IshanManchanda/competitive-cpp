#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long int n, k;
	vector <long long int> a;
	long long int l, t, min, max;

	cin >> n >> k;
	cin >> l;
	min = l;
	max = l;
	for (int i = 0; i < n-2; i++) {
		cin >> t;
		a.push_back(l + t);
		l = t;
	}
	cin >> t;
	min += t;
	max += t;
	sort(a.begin(), a.end());
	for (int i = 0; i < k-1; i++) {
		min += a[i];
		max += a[n-i-2];
	}
	cout << min << " " << max << '\n';
}
