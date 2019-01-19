#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long N, b, c, t = 0;
	cin >> N;
	pair<long long, long long> a[N];
	for (long long i = 0; i < N; i++) {
		cin >> a[i].second >> b >> c;
		a[i].first = b + c;
	}
	sort(a, a + N, greater<>());
	t = a[0].first + a[0].second;
	for (long long i = 1; i < N; i++) {
		a[i].second += a[i - 1].second;
		t = max(t, a[i].first + a[i].second);
	}
	cout << t << endl;
}
