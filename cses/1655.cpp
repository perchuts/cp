#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

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

void solve(){
	int n; cin >> n;
	vector<int> v(n);
	int ans = 0, h = 0;
	for (auto& x : v) cin >> x;
	vector<vector<int>> trie(32*n, vector<int>(2, 0));
	for (int i = 0; i < 30; ++i) trie[h][0] = h+1, h++; 
	for (int i = 0, x = 0; i < n; ++i) {
		x ^= v[i];
		ckmax(ans, x);
		int cur = 0, val = 0;
		for (int j = 29; ~j; --j) {
			int mee = ((x >> j)&1) ^ 1;
			if (trie[cur][mee]) val += (1 << j), cur = trie[cur][mee];
			else cur = trie[cur][mee^1];
		}
		ckmax(ans, val), cur = 0;
		for (int j = 29; ~j; --j) {
			int mee = (x>>j)&1;
			if (!trie[cur][mee]) trie[cur][mee] = ++h;
			cur = trie[cur][mee];
		}
	}
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
