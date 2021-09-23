#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (ll i = (a); i < (b); ++i)
#define MOD 998244353

typedef long long ll;
//typedef __int128_t lll;
typedef pair<int,int> pi;
typedef vector<int> vi;

const ll MAX = 1000001;

// array to store prime factors
ll factor[MAX] = { 0 };

// function to generate all prime factors
// of numbers from 1 to 10^6
void generatePrimeFactors()
{
	factor[1] = 1;

	// Initializes all the positions with their value.
	for (ll i = 2; i < MAX; i++)
		factor[i] = i;

	// Initializes all multiples of 2 with 2
	for (ll i = 4; i < MAX; i += 2)
		factor[i] = 2;

	// A modified version of Sieve of Eratosthenes to
	// store the smallest prime factor that divides
	// every number.
	for (ll i = 3; i * i < MAX; i++) {
		// check if it has no prime factor.
		if (factor[i] == i) {
			// Initializes of j starting from i*i
			for (ll j = i * i; j < MAX; j += i) {
				// if it has no prime factor before, then
				// stores the smallest prime divisor
				if (factor[j] == j)
					factor[j] = i;
			}
		}
	}
}

// function to calculate number of factors
ll calculateNoOFactors(ll n)
{
	if (n == 1)
		return 1;

	ll ans = 1;

	// stores the smallest prime number
	// that divides n
	ll dup = factor[n];

	// stores the count of number of times
	// a prime number divides n.
	ll c = 1;

	// reduces to the next number after prime
	// factorization of n
	ll j = n / factor[n];

	// false when prime factorization is done
	while (j != 1) {
		// if the same prime number is dividing n,
		// then we increase the count
		if (factor[j] == dup)
			c += 1;

			/* if its a new prime factor that is factorizing n,
			   then we again set c=1 and change dup to the new
			   prime factor, and apply the formula explained
			   above. */
		else {
			dup = factor[j];
			ans = (ans * ((c + 1) % MOD)) % MOD;
			c = 1;
		}

		// prime factorizes a number
		j = j / factor[j];
	}

	// for the last prime factor
	ans = (ans * ((c + 1) % MOD)) % MOD;

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n;
	cin >> n;
	ll a[n + 1], prefix[n + 1];

	a[0] = 0;
	a[1] = 1;
	a[2] = 3;
	prefix[0] = 0;
	prefix[1] = 1;
	prefix[2] = 4;
	if (n < 3) {
		cout << a[n] << flush;
		return 0;
	}

	generatePrimeFactors();

	REP(i, 3, n + 1) {
		a[i] = (prefix[i - 1] + calculateNoOFactors(i)) % MOD;
		prefix[i] = (a[i] + prefix[i - 1])  % MOD;
	}
	cout << a[n] << flush;
}
