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

void solve(){
	int n, m; cin >> n >> m;
	vector<int> mark(maxn);
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		for (int j = 1; j * j <= x; ++j) {
			if (x % j == 0) mark[j] = mark[x/j] = 1;
		}
	}
	mark[1] = 0;
	vector<int> v;
	for (int i = 1; i <= m; ++i) {
		int ok = 1;
		for (int j = 1; j * j <= i; ++j) {
			if (i % j == 0) ok &= (mark[j] == mark[i/j] && mark[j] == 0);
		}
		if (ok) v.pb(i);
	}
	cout << sz(v) << endl;
	for (auto x : v) cout << x << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
