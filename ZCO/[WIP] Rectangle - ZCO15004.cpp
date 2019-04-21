#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, i1, i2, x1, x2;
	cin >> n;
	pair<int, int> points[n];

	for (int i = 0; i < n; i++) {
		cin >> points[i].x >> points[i].y;
	}
	sort(points, points + n);

	m = 500 * max(points[0].x, 100000 - points[n - 1].x);
	for (int i = 1; i < n; i++) {
		if (points[i].x == points[i - 1].x) {
			continue;
		}

		i1 = i - 1;
		i2 = i + 1;

		while (i1 >= 0 && points[i1].y >= points[i].y) {
			i1--;
		}
		while (i2 <= n - 1 && points[i2].y >= points[i].y) {
			i2++;
		}

		x1 = (i1 == -1) ? 0 : points[i1].x;
		x2 = (i2 == n) ? 100000 : points[i2].x;

		m = max(m, max(points[i].y * (x2 - x1), 500 * (points[i].x - points[i - 1].x)));
	}
	cout << m;
}
