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
	int n; cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	// posso ter no maximo 1 cara ganhando n-1, no maximo 2 ganhando n-2, and so on
	set<ii> s;
	for (int i = 0; i < n; ++i) if (v[i]) s.insert({-v[i], i});
	vector<ii> ans;
	while (!s.empty()) {
		auto [X, Y] = *begin(s);
		X *= -1;
		s.erase(begin(s));
		vector<ii> nv;
		if (sz(s) < X) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
		for (int i = 0; i < X; ++i) {
			nv.pb(*begin(s));
			s.erase(begin(s));
			ans.pb({Y, nv.back().second});
		}
		for (auto [x, y] : nv) {
			if (x != -1) s.insert({x+1, y});
		}
	}
	cout << sz(ans) << endl;
	for (auto [x, y] : ans) cout << x + 1 << ' ' << y + 1 << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
