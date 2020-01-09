#include <bits/stdc++.h>
using namespace std;


struct exam {
	long long start;
	long long end;
};

bool compare(exam a, exam b) {
	return a.start < b.start;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long N, V, W, low, high, mid, reach, leave, m = 1000007;
	cin >> N >> V >> W;
	exam n[N + 1];
	long long v[V + 1], w[W + 1];

	for (long long i = 0; i < N; i++) { cin >> n[i].start >> n[i].end; }
	for (long long i = 0; i < V; i++) { cin >> v[i]; }
	for (long long i = 0; i < W; i++) { cin >> w[i]; }

	sort(n, n + N, compare);
	sort(v, v + V);
	sort(w, w + W);

	for (long long i = 0; i < N; i++) {
		exam c = n[i];
		if (v[0] > c.start) {
			continue;
		}
		if (w[W - 1] < c.end) {
			continue;
		}

		if (v[V - 1] <= c.start) {
			leave = v[V - 1];
		}
		else {
			low = 0;
			high = V - 1;
			while (high > low) {
				mid = (low + high) / 2;
				if (v[mid] > c.start) {
					high = mid;
				} else {
					low = mid + 1;
				}
			}
			leave = v[low - 1];
		}

		if (w[0] >= c.end) {
			reach = w[0];
		}
		else {
			low = 0;
			high = W - 1;
			while (high > low) {
				mid = (low + high) / 2;
				if (w[mid] > c.end) {
					high = mid;
				} else {
					low = mid + 1;
				}
			}
			if (w[high - 1] < c.end) { reach = w[high]; }
			else { reach = w[high - 1]; }
		}

		if ((reach - leave + 1) < m) {
			m = reach - leave + 1;
		}
	}
	cout << m << endl;
}
