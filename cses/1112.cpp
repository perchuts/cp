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

void solve(){
 	int n; cin >> n;
	string s; cin >> s;
	int m = sz(s);
	// YAY primeira questao de automatos!
	vector automaton(m+1, vector(26, 0));
	vector<int> pi(m);
	for (int i = 0; i < m; ++i) {
		for (char j = 'A'; j <= 'Z'; ++j) {
			if (s[i] == j) automaton[i][j-'A'] = i+1;
			else if (i == 0) automaton[i][j-'A'] = 0;
			else {
				int k = pi[i-1];
				while (k and s[k] != j) k = pi[k-1];
				if (s[k] == j) k++;
				automaton[i][j-'A'] = k;
			}
		}
		if (i) {
			int j = pi[i-1];
			while (j and s[i] != s[j]) j = pi[j-1];
			if (s[i] == s[j]) j++;
			pi[i] = j;
		}
	}
	vector dp(n+1, vector(m+1, 0));
	dp[0][0] = 1;
	int ans = 1;
	for (int i = 1; i <= n; ++i) ans = ans * 26 % mod;
	// como o automato ta de tras pra frente, melhor fazer a dp do mesmo jeito
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int c = 0; c < 26; ++c) {
				int prox = automaton[j][c];
				if (prox == m) continue;
				dp[i+1][prox] = (dp[i+1][prox] + dp[i][j]) % mod;
			}
		}
	}
	for (int i = 0; i < m; ++i) ans = (ans + mod - dp[n][i]) % mod;
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
