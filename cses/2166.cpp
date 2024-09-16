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
 	int n, q; cin >> n >> q;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	struct node {
		int prmx = 0, totval = 0;
		node() {}
	};
	node nulo;
	vector<node> seg(4*n);
	auto merge = [&] (node a, node b) {
		node ans;
		ans.totval = a.totval + b.totval;
		ans.prmx = max(a.prmx, a.totval + b.prmx);
		return ans;
	};
	auto upd = [&] (auto&& self, int i, int l, int r, int x, int k) -> void {
		if (l == r) {
			seg[i].totval = k;
			seg[i].prmx = max(0ll, k);
			return;
		}
		int md = (l + r) / 2;
		if (x <= md) self(self, 2*i, l, md, x, k);
		else self(self, 2*i+1, md+1, r, x, k);
		seg[i] = merge(seg[2*i], seg[2*i+1]);
	};
	auto query = [&] (auto&& self, int i, int l, int r, int x, int y) -> node {
		if (r < x or y < l) return nulo;
		if (x <= l && r <= y) return seg[i];
		int md = (l + r) / 2;
		return merge(self(self, 2*i, l, md, x, y), self(self, 2*i+1, md+1, r, x, y));
	};
	for (int i = 1; i <= n; ++i) upd(upd,1, 1, n, i, v[i-1]);
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int k, u; cin >> k >> u;
			upd(upd, 1, 1, n, k, u);
		} else {
			int l, r; cin >> l >> r;
			cout << query(query,1, 1, n, l, r).prmx << endl;
		}
	}
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
