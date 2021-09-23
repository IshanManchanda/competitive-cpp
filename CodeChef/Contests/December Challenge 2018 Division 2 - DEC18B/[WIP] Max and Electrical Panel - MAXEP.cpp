#include <bits/stdc++.h>
using namespace std;

long long min(long long a, long long b) { return (a > b) ? b : a; }

void bin(long long l, long long r) {
	long long temp, mid = (l + r) / 2;
	if (l == r) {
		cout << 1 << " " << l << endl;
		cin >> temp;

		if (temp) {
			cout << 3 << " " << l << endl;
		}
		else {
			cout << 3 << " " << l - 1 << endl;
		}
		return;
	}

	cout << 1 << " " << mid << endl;
	cin >> temp;
	if (temp) {
		cout << 2 << endl;
		bin(l, mid - 1);
	}
	else {
		bin(mid + 1, r);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long  n, c, l, r = 1, inpt;
	cin >> n >> c;

	while (true) {
		cout << 1 << " " << r << endl;
		cin >> inpt;
		if (inpt) {
			cout << 2 << endl;
			break;
		}
		r = min(2 * r, n);
	}
	l = r / 2;

	bin(l, r);
}
