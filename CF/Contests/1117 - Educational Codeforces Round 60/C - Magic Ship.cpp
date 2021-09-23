# include <bits/stdc++.h>
using namespace std;
#define MAX 100002

pair<long long, long long> mov[MAX];
long long dx, dy, n;

bool check(long long t) {
	long long cycles = t / n;
	long long left = t % n;

	long long x3 = mov[n].first * cycles + mov[left].first;
	long long y3 = mov[n].second * cycles + mov[left].second;

	long long dist = abs(dx - x3) + abs(dy - y3) - t;
	return (dist < 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long x1, y1, x2, y2;
	char a;
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	dx = x2 - x1;
	dy = y2 - y1;
	mov[0] = {0, 0};

	for (int i = 0; i < n; i++) {
		cin >> a;

		if (a == 'U')
			mov[i + 1] = make_pair(mov[i].first, mov[i].second + 1);

		else if (a == 'D')
			mov[i + 1] = make_pair(mov[i].first, mov[i].second - 1);

		else if (a == 'L')
			mov[i + 1] = make_pair(mov[i].first - 1, mov[i].second);

		else
			mov[i + 1] = make_pair(mov[i].first + 1, mov[i].second);
	}

	long long upper = 1;
	while (!check(upper)) {
		upper <<= 1;
		if (upper > 5e17) {
			cout << -1 << endl;
			return 0;
		}
	}
	long long lower = (upper >> 1) + 0;

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
