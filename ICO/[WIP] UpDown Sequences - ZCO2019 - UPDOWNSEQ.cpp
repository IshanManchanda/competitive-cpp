/*
Even index should be >= odd index ==>
Odd index should be <= even index


Store 2 values for i: Longest up-down seq ending at i
	where i is an even index and
	where i is an odd index


Calculate dynamically:
	If a[i] = a[i - 1],
		then both conditions are satisfied, so dp[i][even / odd] = dp[i - 1][even / odd]

	If a[i] > a[i - 1],
		then even condition is satisfied, so dp[i][even] = dp[i - 1][even] + 1.
		Also, odd condition isn't satisfied. dp[i][odd] = 1

	If a[i] < a[i - 1],
		then odd condition is satisfied, so dp[i][odd] = dp[i - 1][odd] + 1.
		Also, even condition isn't satisfied. dp[i][even] = 1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}
