#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
	
using namespace std;
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

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
	vector<iii> hor, ver;
	for (int i = 0; i < n; ++i) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		if (a == c) {
			if (b + 1 >= d) continue;
			hor.pb({a, b, d});
		} else {
			assert(b == d);
			if (a + 1 >= c) continue;
			ver.pb({b, a, c});
		}
	}
	vector<array<int, 4>> events;
	// coordenada y, tipo de evento, l, r
	for (auto [x, y, z] : hor) events.pb({x, 2, y, z});
	int z = 0;
	for (auto [x, l, r] : ver) {
		events.pb({r, 1, x, z});
		events.pb({l+1, 0, x, z});
		z++;
	}
	sort(all(events));
	ord_set<ii> s;
	ll ans = 0;
	for (auto [y, tipo, l, r] : events) {
		if (tipo == 0) {
			s.insert({l, r});
		} else if (tipo == 1) {
			s.erase({l, r});
		} else {
			ans += s.order_of_key({r-1, inf}) - s.order_of_key({l, inf});
		}
	}
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
