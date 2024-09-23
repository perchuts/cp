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
	vector<int> v(n * (n-1) / 2);
	multiset<int> mt;
	for (auto& x : v) cin >> x, mt.insert(x);
	sort(all(v));
	vector<int> ans;
	auto explore = [&] (auto&& self, multiset<int> m, vector<int> vals) -> bool {
			if (m.empty()) {
				ans = vals;
				return true;
			}
			auto vx = *begin(m);
			int k = vx - vals[0];
			if (k > 0) {
				bool ok = 1;
				for (auto x : vals) {
					auto it = m.find(x + k);
					if (it == end(m)) {
						ok = false;
						break;
					}
					m.extract(x + k);
				}
				if (ok) {
					vals.pb(k);
					if (vals.end()[-2] <= vals.back() and self(self, m, vals)) return true;
				}
			}
			return false;
	};
	for (int i = 2; i < sz(v); ++i) {
		vector<int> vals;
		int v12 = v[0], v13 = v[1], v23 = v[i];
		int v1 = (v12 + v13 + v23);
		if (v1 & 1) continue;
		v1 = v1/2 - v23;
		if (v1 <= 0) continue;
		bool ok = 1;
		vals.pb(v1);
		for (int j = 0; j < i; ++j) {
			vals.pb(v[j] - v1);
			if (v[j] - v1 <= 0 or vals.back() < vals.end()[-2]) {
				ok = 0;
				break;
			}
		}
		if (!ok) continue;
		auto mmt = mt;
		for (int j = 0; j < sz(vals); ++j) for (int k = j + 1; k < sz(vals); ++k) {
			auto it = mmt.find(vals[j] + vals[k]);
			if (it == end(mmt)) {
				ok = 0;
				break;
			}
			mmt.erase(it);
		}
		if (!ok) continue;
		if (explore(explore, mmt, vals)) {
			for (auto x : ans) cout << x << ' ';
			cout << endl;
			exit(0);
		}
	}
	assert(false);
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
