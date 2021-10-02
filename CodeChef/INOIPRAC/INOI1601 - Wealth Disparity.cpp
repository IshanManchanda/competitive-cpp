// https://www.codechef.com/INOIPRAC/problems/INOI1601
#include <bits/stdc++.h>
using namespace std;

#define NEG_INF -1000

struct node {
	long long s, p, m;
	bool l;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, x, ans = NEG_INF;
	cin >> n;

	node a[n];
	bool vis[n];
	for (auto  i = 0; i < n; ++i) {
		cin >> a[i].s;
		a[i].l = true;
		a[i].m = a[i].s;
		vis[i] = false;
	}

	for (auto i = 0; i < n; ++i) {
		cin >> a[i].p;
		if (a[i].p != -1) {
			--a[i].p;
			a[a[i].p].l = false;
		}
	}

	queue<long long> q;
	for (auto i = 0; i < n; ++i)
		if (a[i].l) {
			q.push(i);
			vis[i] = true;
		}

	while (!q.empty()) {
		x = q.front();
		q.pop();
		if (a[x].p != -1) {
			ans = max(ans, a[a[x].p].s - a[x].m);
			a[a[x].p].m = min(a[a[x].p].m, a[x].m);

			if (!vis[a[x].p])
				q.push(a[x].p);
		}
	}

	cout << ans << endl;
}
