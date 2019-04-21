#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, n, s, diff, m;
	long long total, ans;

	cin >> t;
	for (int tn = 1; tn < t + 1; tn++) {
		cin >> n >> s;
		int a[n];
		vector<int> arr[n + 1];

		ans = -1;
		m = -1;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m = max(m, a[i]);
		}

//		copy(begin(temp), end(temp), begin(arr[0]));
//		copy(begin(temp), end(temp), begin(arr[1]));
//		memset(arr[0], 0, sizeof(arr[0]));
//		memset(arr[1], 0, sizeof(arr[1]));
//		for (int i = 0; i < n + 1; i++) {
//			for (int j = 0; j < 100005; j++) {
//				arr[i][j] = 0;
//			}
//		}

		arr[0].resize(100005);
		arr[1].resize(100005);
		arr[1][a[0]] = 1;

		for (int i = 1; i < n; i++) {
			arr[i + 1].resize(100005);
			copy(begin(arr[i]), end(arr[i]), begin(arr[i + 1]));
			arr[i + 1][a[i]] += 1;
		}

		for (int i = 1; i < n + 1; i++) {
			for (int j = 0; j < i; j++) {
				total = 0;
				for (int k = 0; k < m + 1; k++) {
					diff = arr[i][k] - arr[j][k];
//					cout << diff;
					if (diff <= s) {
						total += diff;
					}
				}

				ans = max(ans, total);
			}
		}

		cout << "Case #" << tn << ": " << ans << '\n';
	}
	return 0;
}
