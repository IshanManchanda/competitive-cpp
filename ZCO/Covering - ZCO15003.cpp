#include<bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int n, m;
	cin >> n;
	pair<int, int> intervals[n];
	for (int i = 0; i < n; i++) {
		cin >> intervals[i].first >> intervals[i].second;
	}

	sort(intervals, intervals + n);
	m = n;
	for (int i = 0; i < n - 1; i++) {
		if (intervals[i + 1].first <= intervals[i].second) {
			m--;
			intervals[i + 1].second = min(intervals[i].second, intervals[i + 1].second);
		}
	}
	cout << m;
}
