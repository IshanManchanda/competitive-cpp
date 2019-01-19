#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;
	K--;

	if (N == 1) {
		cout << 0;
		return 0;
	}

	long long a[N], forward[N], backward[N];
	long long m = -100000001;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		forward[i] = 0;
	}

	if (K != N) {
		forward[K + 1] = a[K + 1];
		for (int i = K + 2; i < N; i++) {
			forward[i] = max(forward[i - 1], forward[i - 2]) + a[i];
		}
	}
	backward[0] = a[0];
	backward[1] = a[0] + a[1];
	for (int i = 2; i < N; i++) {
		backward[i] = max(backward[i - 1], backward[i - 2]) + a[i];
	}

	for (int i = K; i < N; i++) {
		m = max(m, forward[i] + backward[i] - a[i]);
	}
	cout << m << endl;

}
