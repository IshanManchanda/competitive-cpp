# include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, n, k, l, r, mr, mnk, nkos;
	int a[100001];
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int ls[n], rs[n], ks[100001], kos[100001];
		for (int &i : a) {
			i = 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> ls[i] >> rs[i];
			for (int j = ls[i]; j <= rs[i]; j++) {
				a[j]++;
			}
		}

		ks[0] = 0;
		kos[0] = 0;
		for (int i = 1; i < 100001; i++) {
			if (a[i] == k) {
				ks[i] = 1 + ks[i - 1];
				kos[i] = kos[i - 1];
			}
			else if (a[i] == k + 1) {
				kos[i] = 1 + kos[i - 1];
				ks[i] = ks[i - 1];
			}
		}

		mnk = 0;
		for (int i = 0; i < n; i++) {
			mnk = max(mnk, kos[rs[i]] - kos[ls[i] - 1] + ks[ls[i] - 1] - ks[rs[i]] + ks[100000]);
		}
		cout << mnk;
	}
}
