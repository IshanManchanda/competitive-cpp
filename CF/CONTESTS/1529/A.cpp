#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = (a); i < (b); ++i)

typedef long long ll;
//typedef __int128_t lll;
typedef pair<int,int> pi;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll t, min_so_far, min_count, temp, n;
	cin >> t;
	REP(i, 0, t) {
		cin >> n;
		min_so_far = LLONG_MAX;
		REP(j, 0, n){
			cin >> temp;
			if (temp == min_so_far)
				++min_count;
			else if (temp < min_so_far) {
				min_count = 1;
				min_so_far = temp;
			}
		}

		cout << n - min_count << "\n";
	}
	cout << endl;
}
