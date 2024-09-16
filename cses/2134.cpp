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

const int INF = 2e9+1;
const int mod = 1e9+7;
const int MAX = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

int seg[2 * MAX];

void build_seg(int n) {
	for (int i = n - 1; i; i--) seg[i] = max(seg[2*i], seg[2*i+1]);
}

int query(int n, int a, int b) {
	int ret = 0;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret = max(ret, seg[a]);
		if (b % 2 == 0) ret = max(ret, seg[b]);
	}
	return ret;
}

void update(int n, int p, int x) {
	seg[p += n] = x;
	while (p /= 2) seg[p] = max(seg[2*p], seg[2*p+1]);
}

namespace hld {
	vector<int> g[MAX];
	int pos[MAX], sz[MAX];
	int peso[MAX], pai[MAX];
	int h[MAX], v[MAX], t;

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = peso[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i != p) {
			pai[i] = k;
			h[i] = (i == g[k][0] ? h[k] : i);
			build_hld(i, k, f); sz[k] += sz[i];

			if (sz[i] > sz[g[k][0]] or g[k][0] == p) swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(int root = 0) {
		t = 0;
		build_hld(root);
		for (int i = 0; i < t; ++i) seg[i+t] = v[i];
		build_seg(t);
	}
	int query_path(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return query(t, pos[b], pos[a]);
		return max(query(t, pos[h[a]], pos[a]), query_path(pai[h[a]], b));
	}
	void update_path(int a, int b, int x) { update(t, pos[a], x); }
}

void solve(){
 	int n, q; cin >> n >> q; 
	for (int i = 0; i < n; ++i) cin >> hld::peso[i];
	for (int i = 0; i < n-1; ++i) {
		int u, v; cin >> u >> v;
		--u, --v;
		hld::g[u].pb(v);
		hld::g[v].pb(u);
	}
	hld::build();
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int s, x; cin >> s >> x;
			--s;
			hld::update_path(s, s, x);
		} else {
			int u, v; cin >> u >> v;
			--u, --v;
			cout << hld::query_path(u, v) << ' ';
		}
	}
	cout << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
