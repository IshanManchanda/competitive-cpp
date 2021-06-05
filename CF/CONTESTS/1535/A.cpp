#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = (a); i < (b); ++i)
#define RREP(i,a,b) for (int i = (a); i > (b); --i)

#define NEG_INF (-LLONG_MAX)

typedef long long ll;
//typedef __int128_t lll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, s1, s2, s3, s4;

	cin >> t;
	while (t--) {
		cin >> s1 >> s2 >> s3 >> s4;

		if (min(s1, s2) > max(s3, s4) || min(s3, s4) > max(s1, s2))
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	cout << flush;
}
