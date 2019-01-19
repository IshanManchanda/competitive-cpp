#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	long long a, b;

	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (a == b) {
			cout << "=" << endl;
		}
		else if (a > b) {
			cout << ">" << endl;
		}
		else {
			cout << "<" << endl;
		}
	}
}
