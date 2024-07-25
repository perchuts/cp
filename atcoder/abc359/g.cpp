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
// LCA com RMQ
//
// Assume que um vertice eh ancestral dele mesmo, ou seja,
// se a eh ancestral de b, lca(a, b) = a
// dist(a, b) retorna a distancia entre a e b
//
// Complexidades:
// build - O(n)
// lca - O(1)
// dist - O(1)

template<typename T> struct rmq {
	vector<T> v;
	int n; static const int b = 30;
	vector<int> mask, t;

	int op(int x, int y) { return v[x] < v[y] ? x : y; }
	int msb(int x) { return __builtin_clz(1)-__builtin_clz(x); }
	rmq() {}
	rmq(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
		for (int i = 0, at = 0; i < n; mask[i++] = at |= 1) {
			at = (at<<1)&((1<<b)-1);
			while (at and op(i, i-msb(at&-at)) == i) at ^= at&-at;
		}
		for (int i = 0; i < n/b; i++) t[i] = b*i+b-1-msb(mask[b*i+b-1]);
		for (int j = 1; (1<<j) <= n/b; j++) for (int i = 0; i+(1<<j) <= n/b; i++)
			t[n/b*j+i] = op(t[n/b*(j-1)+i], t[n/b*(j-1)+i+(1<<(j-1))]);
	}
	int small(int r, int sz = b) { return r-msb(mask[r]&((1<<sz)-1)); }
	T query(int l, int r) {
		if (r-l+1 <= b) return small(r, r-l+1);
		int ans = op(small(l+b-1), small(r));
		int x = l/b+1, y = r/b-1;
		if (x <= y) {
			int j = msb(y-x+1);
			ans = op(ans, op(t[n/b*j+x], t[n/b*j+y-(1<<j)+1]));
		}
		return ans;
	}
};

namespace lca {
	vector<int> g[maxn];
	int v[2*maxn], pos[maxn], dep[2*maxn];
	int t;
	rmq<int> RMQ;

	void dfs(int i, int d = 0, int p = -1) {
		v[t] = i, pos[i] = t, dep[t++] = d;
		for (int j : g[i]) if (j != p) {
			dfs(j, d+1, i);
			v[t] = i, dep[t++] = d;
		}
	}
	void build(int n, int root) {
		t = 0;
		dfs(root);
		RMQ = rmq<int>(vector<int>(dep, dep+2*n-1));
	}
	int lca(int a, int b) {
		a = pos[a], b = pos[b];
		return v[RMQ.query(min(a, b), max(a, b))];
	}
	int dist(int a, int b) {
		return dep[pos[a]] + dep[pos[b]] - 2*dep[pos[lca(a, b)]];
	}
}
vector<pair<int, int>> virt[maxn];

#warning lembrar de buildar o LCA antes
int build_virt(vector<int> v) {
	auto cmp = [&](int i, int j) { return lca::pos[i] < lca::pos[j]; };
	sort(v.begin(), v.end(), cmp);
	for (int i = v.size()-1; i; i--) v.push_back(lca::lca(v[i], v[i-1]));
	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) virt[v[i]].clear();
	for (int i = 1; i < v.size(); i++) virt[lca::lca(v[i-1], v[i])].clear();
	for (int i = 1; i < v.size(); i++) {
		int parent = lca::lca(v[i-1], v[i]);
		int d = lca::dist(parent, v[i]);
#warning soh to colocando aresta descendo
		virt[parent].emplace_back(v[i], d);
	}
	return v[0];
}
int sz[maxn], a[maxn], answer = 0;
int get(int u, int target) {
	int qt = 0;
	sz[u] = (a[u] == target);
	for (auto [v, w] : virt[u]) {
		int new_dist = get(v, target) + sz[v] * w;
		answer += sz[u] * new_dist + sz[v] * qt;
		sz[u] += sz[v], qt += new_dist;
	}
	return qt;
}
void solve(){
	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v; cin >> u >> v; --u, --v;
		lca::g[u].pb(v), lca::g[v].pb(u);
	}
	vector<vector<int>> comps(n);
	for (int i = 0; i < n; ++i) cin >> a[i], a[i]--, comps[a[i]].pb(i);
	lca::build(n, 0);
	for (int i = 0; i < n; ++i) {
		if (comps[i].empty()) continue;
		int r = build_virt(comps[i]);
		get(r, i);
	}
	cout << answer << endl;

}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
