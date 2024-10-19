#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int ll

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;

const int inf = 2e9+1;
const int mod = 1e9+7;
const int maxn = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

bool solve(int n, vector<int> v){
	vector dp(2, vector(2, vector(n+2, vector(n+2, 0))));
	// dp[0][0][0][0] = 1
	dp[0][0][n+1][n+1] = 1;
	int L = n+1;
	for (int i = 1; i <= n; ++i) {
		int C = v[i-1];
		for (int j = 1; j <= n; ++j) {
			// se eu colocar ele em cima do que ja existe (em cima da stack i-1!)
			if (j == C or j == L) continue;
			if (v[i-1] < L) dp[0][0][C][j] |= dp[0][0][L][j], dp[0][1][C][j] |= dp[0][1][L][j];
			if (v[i-1] > L) dp[1][0][C][j] |= (dp[1][0][L][j] | dp[0][0][L][j]), dp[1][1][C][j] |= (dp[1][1][L][j] | dp[0][1][L][j]);
			// agora, vou colocar ele em cima da outra stack!
			if (j < C) {
				dp[1][0][C][L] |= (dp[0][1][L][j] | dp[0][0][L][j]);
				dp[1][1][C][L] |= (dp[1][1][L][j] | dp[1][0][L][j]);
			} else if (j > C) {
				dp[0][0][C][L] |= dp[0][0][L][j];
				dp[0][1][C][L] |= dp[1][0][L][j];
			}
		}
		// usando apenas uma stack
		if (L < C) {
			dp[1][0][C][n+1] |= (dp[1][0][L][n+1] | dp[0][0][L][n+1]);
		} else {
			dp[0][0][C][n+1] |= dp[0][0][L][n+1];
		}
		L = v[i-1];
	}
	for (int j = 1; j <= n+1; ++j) {
		if (dp[0][0][L][j] == 1 or dp[1][0][L][j] == 1 or dp[0][1][L][j] == 1 or dp[1][1][L][j]) return true;
	}
	return false;
}

// 1 4 3 5 2
// 2 3 1
// 1 3 2
//

int32_t main(){_
	int tt = 1;
	while (true) {
		int n = rnd(3, 5);
		vector<int> p(n); iota(all(p), 1);
		shuffle(all(p), rng);
		bool ans = 0;
		for (int i = 0; i < (1 << n); ++i) {
			vector<int> p1, p2;
			bool ok = 1;
			for (int j = 0; j < n; ++j) {
				if ((i >> j) & 1) p1.pb(p[j]);
				else p2.pb(p[j]);
			}
			for (int j = 1; j < sz(p1)-1; ++j) ok &= !(p1[j-1] < p1[j] and p1[j] > p1[j+1]);
			for (int j = 1; j < sz(p2)-1; ++j) ok &= !(p2[j-1] < p2[j] and p2[j] > p2[j+1]);
			ans |= ok;
			if (ok) break;
		}
		bool my = solve(n, p);
		if (my != ans) {
			cout << "Wrong answer on test " << tt << endl;
			cout << n << endl;
			for (auto x : p) cout << x << ' ';
			cout << endl;
			cout << "Your answer: " << (my ? "Yes" : "No") << endl;
			cout << "Answer: " << (ans ? "Yes" : "No") << endl;
			exit(0);
		}
		cout << "Accepted on test " << tt++ << endl;
	}
}
