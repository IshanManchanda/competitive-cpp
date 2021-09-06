#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB emplace_back
#define MP make_pair
#define MT make_tuple

#define REP(i,a,b) for (ll i = (a); i < (b); ++i)
#define RREP(i,a,b) for (ll i = (a); i > (b); --i)

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define FILE_IN freopen("input.txt", "r", stdin);
#define FILE_OUT freopen("output.txt", "w", stdout);
#define TESTCASES ll tt; cin >> tt; while (tt--)
#define TESTCASES1 ll tt; cin >> tt; REP(ttt, 1, tt + 1)

#define NEG_INF (-LLONG_MAX)
#define FLOAT_EQ(a, b) (abs((a) - (b)) < 1e-9)
#define NEWL "\n";

typedef long long ll;
//typedef __int128_t lll;
//typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<int> vl;
typedef vector<vi> vvl;


int main() {
	FAST_IO

	TESTCASES {
		int a, b, s, x;
		cin >> a >> b;
		s = a;
		--a;
		switch (a % 4) {
			case 0:
				x = a;
				break;
			case 1:
				x = 1;
				break;
			case 2:
				x = a + 1;
				break;
			default:
				x = 0;
				break;
		}
		if (x == b) ;
		else if ((x ^ b) == a + 1)
			s += 2;
		else
			++s;
		cout << s << "\n";
	}

	cout << flush;
}
