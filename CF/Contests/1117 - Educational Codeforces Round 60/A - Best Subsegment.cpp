#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m = -1, mi;
	vector<int> mis;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > m) {
			m = a[i];
			mi = i;
			mis = {i};
		} else if (a[i] == m) {
			mis.push_back(i);
		}
	}

	int l = 1, ml = 0;
	for (int i = 0; i < mis.size() - 1; i++) {
		if (mis[i + 1] - mis[i] == 1) {
			l++;
		} else {
			ml = max(l, ml);
			l = 1;
		}
	}
	cout << max(ml, l);
}
