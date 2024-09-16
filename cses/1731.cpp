#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;

const int inf = 2e9+1;
const int mod = 1e9+7;
const int maxn = 1e6+10;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

int trie[maxn][27];

void solve(){
	string s; cin >> s;
	int n = sz(s), h = 1;
int k; cin >> k;
	for (int i = 0; i < k; ++i) {
		string s2; cin >> s2;
		int cur = 0;
		for (int j = sz(s2)-1; j >= 0; --j) {
			if (trie[cur][s2[j]-'a'] == 0) trie[cur][s2[j]-'a'] = h++;
			cur = trie[cur][s2[j]-'a'];
		}
		trie[cur][26]++;
	}
	vector<int> dp(n+1);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		int cur = 0;
		for (int j = i; j >= 1; --j) {
			int prox = s[j-1] - 'a';
			if (trie[cur][prox] == 0) break;
			cur = trie[cur][prox];
			dp[i] += trie[cur][26] * dp[j-1];
		}
		dp[i] %= mod;
	}
	cout << dp[n] << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
