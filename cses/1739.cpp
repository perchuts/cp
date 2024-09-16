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

void solve(){
 	int n, q; cin >> n >> q;
	vector val(n, vector(n, 0));
	struct SegTree {
		vector<int> seg;
		int n;
		SegTree(){}
		SegTree(int n_): n(n_) {
			seg = vector<int>(4*n, 0);
		};
		void upd(int i, int l, int r, int x, int k) {
			if (l == r) {
				seg[i] += k;
				return;
			}
			int md = (l + r) / 2;
			if (x <= md) upd(2*i, l, md, x, k);
			else upd(2*i+1, md+1, r, x, k);
			seg[i] = seg[2*i] + seg[2*i+1];
		}
		int query(int i, int l, int r, int x, int y) {
			if (x <= l && r <= y) return seg[i];
			if (r < x or y < l) return 0;
			int md = (l + r) / 2;
			return query(2*i, l, md, x, y) + query(2*i+1, md+1, r, x, y);
		}
	};
	vector<SegTree> seg2d(4*n);
	for (int i = 0; i < 4*n; ++i) seg2d[i] = SegTree(n);
	auto upd = [&] (auto&& self, int i, int l, int r, int x, int y, int k) -> void {
		seg2d[i].upd(1, 0, n-1, y, k);
		if (l == r) return;
		int md = (l + r) / 2;
		if (x <= md) self(self, 2*i, l, md, x, y, k);
		else self(self, 2*i+1, md+1, r, x, y, k);
	};
	auto query = [&] (auto&& self, int i, int l, int r, int x1, int y1, int x2, int y2) -> int {
		if (x1 <= l && r <= x2) return seg2d[i].query(1, 0, n-1, y1, y2);
		if (r < x1 or x2 < l) return 0;
		int md = (l + r) / 2;
		return self(self, 2*i, l, md, x1, y1, x2, y2) + self(self, 2*i+1, md+1, r, x1, y1, x2, y2);
	};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char c; cin >> c;
			val[i][j] = (c == '*');
			upd(upd, 1, 0, n-1, i, j, val[i][j]);
		}
	}
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int x, y; cin >> x >> y;
			--x, --y;
			val[x][y] ^= 1;
			int k = (val[x][y] ? 1 : -1);
			upd(upd, 1, 0, n-1, x, y, k); 
		} else {
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
			--x1, --y1, --x2, --y2;
			cout << query(query, 1, 0, n-1, x1, y1, x2, y2) << endl;
		}
	}
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
