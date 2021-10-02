#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b, ca = 0, cb = 0, md = 0, n;
	bool w;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		ca += a;
		cb += b;
		if (ca - cb > md) {
			md = ca - cb;
			w = false;
		} else if (cb - ca > md) {
			md = cb - ca;
			w = true;
		}
	}
	cout << int (w) + 1 << ' ' << md << endl;
}
