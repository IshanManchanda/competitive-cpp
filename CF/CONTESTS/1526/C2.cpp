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

	int n;
	ll health = 0, a;
	priority_queue <ll, vector<ll>, greater<>> q;

	cin >> n;
	REP(i, 0, n) {
		cin >> a;
		health += a;
		q.push(a);

		while (health < 0) {
			health -= q.top();
			q.pop();
		}
	}

	cout << (int) q.size() << flush;
}
