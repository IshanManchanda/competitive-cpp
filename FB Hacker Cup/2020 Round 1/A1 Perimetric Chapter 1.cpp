//#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()

#define PB emplace_back
#define MP make_pair
#define MT make_tuple

#define REP(i, a, b) for (ll i = (a); i < (b); ++i)
#define RREP(i, a, b) for (ll i = (a); i > (b); --i)

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define FILE_IN freopen("input.txt", "r", stdin);
#define FILE_OUT freopen("output.txt", "w", stdout);

#define TESTCASES ll tt; cin >> tt; while (tt--)
#define TESTCASES1 ll tt; cin >> tt; REP(ttt, 1, tt + 1)
#define CASEOUT cout << "Case #" << ttt << ": "

#define NEG_INF (-LLONG_MAX)
#define FLOAT_EQ(a, b) (abs((a) - (b)) < 1e-9)
#define MOD (1'000'000'007)
//#define MOD_SUM(a, b) ((a) + (b) >= MOD) ? ((a) + (b) - MOD) : ((a) + (b))
#define NEWL "\n";

typedef long long ll;
//typedef __int128_t lll;
//typedef long double ld;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vi> vvl;


int main() {
	FAST_IO
	FILE_IN
	FILE_OUT

	TESTCASES1 {
		int n, k, w, al, bl, cl, dl, ah, bh, ch, dh;
		cin >> n >> k >> w;
		int l[k], h[k];
		REP(i, 0, k) cin >> l[i];
		cin >> al >> bl >> cl >> dl;
		REP(i, 0, k) cin >> h[i];
		cin >> ah >> bh >> ch >> dh;

		ll prod, p;
		prod = p = 2 * (w + h[0]);
		deque<pi> q;
		q.emplace_back(l[0], h[0]);
		REP(i, 1, k) {
			p = (p + 2 * (w - max(0, l[i - 1] + w - l[i]))) % MOD;

			while (!q.empty() && q.front().F + w < l[i]) q.pop_front();
			if (q.empty()) p = (p + 2 * h[i]) % MOD;
			else if (q.front().S < h[i])
				p = (p + 2 * (h[i] - q.front().S)) % MOD;
			prod = (prod * p) % MOD;

			while (!q.empty() && q.back().S <= h[i]) q.pop_back();
			q.emplace_back(l[i], h[i]);
		}
		ll li, hi, li1 = l[k - 1], hi1 = h[k - 1], li2 = l[k - 2], hi2 = h[k - 2];
		REP(i, k, n) {
			li = ((al * li2 + bl * li1 + cl) % dl) + 1;
			hi = ((ah * hi2 + bh * hi1 + ch) % dh) + 1;

			p = (p + 2 * (w - max(0ll, li1 + w - li))) % MOD;

			while (!q.empty() && q.front().F + w < li) q.pop_front();
			if (q.empty()) p = (p + 2 * hi) % MOD;
			else if (q.front().S < hi)
				p = (p + 2 * (hi - q.front().S)) % MOD;
			prod = (prod * p) % MOD;

			while (!q.empty() && q.back().S <= hi) q.pop_back();
			q.emplace_back(li, hi);

			li2 = li1; hi2 = hi1; li1 = li; hi1 = hi;
		}
		CASEOUT << ((prod < 0) ? prod + MOD : prod) << "\n";
	}

	cout << flush;
}
