# include <bits/stdc++.h>
using namespace std;


char a[100001];
vector<pair<int, int>> pos;
int x2, y2, n;
long long pre = INFINITY;


bool check(long long t) {
	if (pos.size() <= t) {
		for (int i = pos.size() - 1; i < t; i++) {
			if (a[i % n] == 'U') {
				pos.emplace_back(make_pair(pos[i].first, pos[i].second + 1));
			}
			else if (a[i % n] == 'D') {
				pos.emplace_back(make_pair(pos[i].first, pos[i].second - 1));
			}
			else if (a[i % n] == 'L') {
				pos.emplace_back(make_pair(pos[i].first - 1, pos[i].second));
			}
			else {
				pos.emplace_back(make_pair(pos[i].first + 1, pos[i].second));
			}
		}
	};
	long long dist = abs(x2 - pos[t].first) + abs(y2 - pos[t].second) - t;
	if (dist >= pre) n = -1;
	pre = dist;
	return (dist < 1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int x1, y1;
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	pos.emplace_back(make_pair(x1, y1));

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long upper = 1;
	while (!check(upper)) {
		if (n == -1) {
			cout << -1;
			return 0;
		}
		upper <<= 1;
	}
	long long lower = upper >> 1;

	while (lower < upper) {
		if (check(lower)) {
			cout << lower;
			return 0;
		}
		long long mid = (lower + upper) / 2;
		if (check(mid)) {
			upper = mid - 1;
		} else {
			lower = mid + 1;
		}
	}
	if (check(lower - 1)) cout << lower - 1;
	else if (check(lower)) cout << lower;
	else cout << lower + 1;
}
