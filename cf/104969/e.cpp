#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
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
	vector<ii> vals;
	int mx = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		int s, q, c, v; cin >> s >> q >> c >> v;
		int cost = min(s*q, (s-1)*c+q);
		vals.emplace_back(v, cost);
	}
	//vals = {{1000, 2}, {1000, 2}, {1, 1}, {1000, 2}};
	for (auto [val, wait] : vals) ckmax(mx, wait), ans += val;
	sort(vals.rbegin(), vals.rend());
	vector<ii> seg(4*mx+1);
	auto upd = [&] (auto&& self, int i, int l, int r, int x, int k) -> void { 
		if (l == r) {
			seg[i].first += k, seg[i].second += k;
			return;
		}	
		int md = (l+r)/2;
		if (x <= md) self(self, 2*i, l, md, x, k);
		else self(self, 2*i+1, md+1, r, x, k);
		seg[i].second = seg[2*i].second + seg[2*i+1].second;
		seg[i].first = min(seg[2*i].first, seg[2*i].second + seg[2*i+1].first);
	};
	auto query = [&] (auto&& self, int i, int l, int r, int x, int y) -> ii {
		if (r < x or y < l or x > y) return make_pair(1e18, 0);
		if (x <= l and r <= y) return seg[i];
		int md = (l + r) / 2;
		auto lx = self(self, 2*i, l, md, x, y);
		auto rx = self(self, 2*i+1, md+1, r, x, y);
		return make_pair(min(lx.first, lx.second+rx.first), lx.second+rx.second);
	};
	for (int i = 1; i <= mx; ++i) upd(upd, 1, 1, mx, i, 1);
	for (auto [val, i] : vals) {
		auto bef = query(query, 1, 1, mx, 1, i-1);
		if (bef.second + query(query, 1, 1, mx, i, mx).first == 0) continue;
		upd(upd, 1, 1, mx, i, -1);
		ans -= val;
	}
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
