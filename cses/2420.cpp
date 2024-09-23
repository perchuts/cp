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
const int mod1 = 1e9+9;
const int mod2 = 998244853;
const int maxn = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

void solve(){
 	int n, q; cin >> n >> q;
	string s; cin >> s;
	mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

	auto uniform = [&] (int l, int r) {
		uniform_int_distribution<int> uid(l, r);
		return uid(rng);
	};
	int P1 = uniform(300, mod1-1), P2 = uniform(300, mod2-1);
	struct node {
		ii h = {0, 0};
		ii rh = {0, 0};
		int qnt = 0;
	} nulo;
	vector<node> seg(4*n);
	vector<int> pot1(n+1, 1), pot2(n+1, 1);
	for (int i = 1; i <= n; ++i) pot1[i] = pot1[i-1] * P1 % mod1, pot2[i] = pot2[i-1] * P2 % mod2;
	auto merge = [&] (node a, node b) {
		node res;
		res.qnt = a.qnt + b.qnt;
		res.h = {(pot1[b.qnt] * a.h.first + b.h.first) % mod1, (pot2[b.qnt] * a.h.second + b.h.second) % mod2};  
		res.rh = {(pot1[a.qnt] * b.rh.first + a.rh.first) % mod1, (pot2[a.qnt] * b.rh.second + a.rh.second) % mod2};  
		return res;
	};
	auto build = [&] (auto&& self, int i, int l, int r) -> void {
		if (l == r) {
			seg[i].h = seg[i].rh = {s[l], s[l]};
			seg[i].qnt = 1;
			return;
		}
		int md = (l+r)/2;
		self(self, 2*i, l, md), self(self, 2*i+1, md+1, r);
		seg[i] = merge(seg[2*i], seg[2*i+1]);
	};
	auto upd = [&] (auto&& self, int i, int l, int r, int x) -> void {
		if (l == r) {
			seg[i].h = seg[i].rh = {s[l], s[l]};
			seg[i].qnt = 1;
			return;
		}
		int md = (l + r) / 2;
		if (x <= md) self(self, 2*i, l, md, x);
		else self(self, 2*i+1, md+1, r, x);
		seg[i] = merge(seg[2*i], seg[2*i+1]);
	};
	auto query = [&] (auto&& self, int i, int l, int r, int x, int y) -> node {
		if (r < x or y < l) return nulo;
		if (x <= l && r <= y) return seg[i];
		int md = (l + r) / 2;
		return merge(self(self, 2*i, l, md, x, y), self(self, 2*i+1, md+1, r, x, y));
	};
	build(build, 1, 0, n-1);
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int k;
			char c;
			cin >> k >> c;
			--k;
			s[k] = c;
			upd(upd, 1, 0, n-1, k);
		} else {
			int l, r; cin >> l >> r;
			--l, --r;
			if (l == r) {
				cout << "YES" << endl;
				continue;
			}
			int par = (r-l+1)%2;
			node a, b;
			if (par) {
				a = query(query, 1, 0, n-1, l, l+(r-l)/2-1);
				b = query(query, 1, 0, n-1, l+(r-l)/2+1, r);
			} else {
				a = query(query, 1, 0, n-1, l, l+(r-l+1)/2-1);
				b = query(query, 1, 0, n-1, l+(r-l+1)/2, r);
			}
			cout << (a.h == b.rh ? "YES" : "NO") << endl;
		}
	}
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
