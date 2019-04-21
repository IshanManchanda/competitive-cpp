# include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, m, k, best = 0, second = 0, temp, answer, q, r;
	cin >> n >> m >> k;
	for (long long i = 0; i < n; i++) {
		cin >> temp;
		if (temp > best) {
			second = best;
			best = temp;
		} else if (temp > second) {
			second = temp;
		}
	}

	if (best == second || k >= m) {
		answer = best * m;
	} else {
		q = m / (k + 1);
		r = m % (k + 1);
		temp = (k * best) + second;
		answer = q * temp + r * best;
	}
	cout << answer;
}
