#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define endl '\n'
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#pragma GCC optimize("Ofast")
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
 
const int inf = 2e9+1;
const int mod = 1e9+7;
const int MAX = 3e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
// Kosaraju
//
// O(n + m)
 
int n;
vector<int> g[MAX];
vector<int> gi[MAX]; // grafo invertido
int vis[MAX];
stack<int> S;
int comp[MAX]; // componente conexo de cada vertice
 
void dfs(int k) {
	vis[k] = 1;
	for (int i = 0; i < (int) g[k].size(); i++)
		if (!vis[g[k][i]]) dfs(g[k][i]);
 
	S.push(k);
}
 
void scc(int k, int c) {
	vis[k] = 1;
	comp[k] = c;
	for (int i = 0; i < (int) gi[k].size(); i++)
		if (!vis[gi[k][i]]) scc(gi[k][i], c);
}
 
void kosaraju() {
	for (int i = 0; i < n; i++) vis[i] = 0;
	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);
 
	for (int i = 0; i < n; i++) vis[i] = 0;
	while (S.size()) {
		int u = S.top();
		S.pop();
		if (!vis[u]) scc(u, u);
	}
}
void solve(){
	int m; cin >> n >> m;
	vector<ii> edg(m);
	for (auto& [x, y] : edg) { cin >> x >> y; --x, --y; }
	vector<int> exist(n), in(n), out(n), repr(n), src, sink;
	vector<vector<int>> g3(n), g1(n), g2(n);
	auto recalc = [&] () {
		for (int i = 0; i < n; ++i) g3[i].clear(), g[i].clear(), gi[i].clear(), g1[i].clear(), g2[i].clear(), exist[i] = in[i] = out[i] = repr[i] = 0;
		for (auto [x, y] : edg) g[x].pb(y), gi[y].pb(x), g1[x].pb(y), g2[y].pb(x);
		src.clear(), sink.clear();
		kosaraju();
		for (int i = 0; i < n; ++i) exist[comp[i]] = 1, repr[comp[i]] = i;
		for (auto [x, y] : edg) {
			if (comp[x] != comp[y]) in[comp[y]]++, out[comp[x]]++, g3[comp[x]].pb(comp[y]), g3[comp[y]].pb(comp[x]);
		}
		for (int i = 0; i < n; ++i) {
			if (exist[i] == 0) continue;
			if (in[i] == 0) src.pb(i);
			if (out[i] == 0) sink.pb(i);
		}
	};
	recalc();
	vector<int> vis2(n, -1);
	vector<ii> repr_comp;
	auto explore = [&] (auto&& self, int u) -> void {
		vis2[u] = 1;	
		for (auto v : g3[u]) if (vis[v] == -1) self(self, v);
		if (in[u] == 0) repr_comp.back().first = repr[u];
		if (out[u] == 0) repr_comp.back().second = repr[u];
	};
	for (int i = 0; i < n; ++i) {
		if (!exist[i] or vis2[i]) continue;
		repr_comp.emplace_back(-1, -1);
		explore(explore, i);
	}
	vector<ii> ans;
	for (int i = 0; i < sz(repr_comp)-1; ++i) {
		edg.pb({repr_comp[i].second, repr_comp[i+1].first});
		ans.pb(edg.back());
	}
	int cnt = accumulate(all(exist), 0);
	if (cnt == 1) {
		cout << sz(ans) << endl;
		for (auto [x, y] : ans) cout << x + 1 << ' ' << y + 1 << endl;
		exit(0);
	}
	vector<vector<ii>> reach(2, vector<ii>(n, make_pair(n, -1)));
	auto go = [&] (bool type) {
		vector<int> deg(n);
		for (int i = 0; i < n; ++i) deg[i] = (type ? in[i] : out[i]);
		queue<int> q;
		for (int i = 0; i < n; ++i) if (exist[i] and deg[i] == 0) q.push(i), reach[type][i] = {i, i};
		while (!q.empty()) {
			auto u = q.front(); q.pop();
			for (auto v : (type ? g1[u] : g2[u])) {
				deg[v]--;
				ckmin(reach[type][v].first, reach[type][u].first);
				ckmax(reach[type][v].second, reach[type][u].second);
				if (deg[v] == 0) q.push(v);
			}
		}
	};
	recalc();
	go(0), go(1);
	// go(0) -> computa sinks alcancaveis
	// go(1) -> computa srcs  alcancaveis
	vector<vector<int>> bad(n);
	for (int i = 0; i < n; ++i) {
		if (!exist[i]) continue;
		if (in[i] == 0) {
			// src
			if (reach[0][i].first == reach[0][i].second) bad[reach[0][i].first].pb(i);
		} else if (out[i] == 0) {
			// sink
			if (reach[1][i].first == reach[1][i].second) bad[reach[1][i].first].pb(i);
		}
	}
	vector<int> special(n);
	for (auto x : src) {
		if (reach[0][x].first != reach[0][x].second) special[x] = 1; 
	}
	for (auto x : sink) {
		if (reach[1][x].first != reach[1][x].second) special[x] = 1; 
	}
	while (true) {
		recalc();
		int k = max(sz(src), sz(sink));
		shuffle(all(src), rng), shuffle(all(sink), rng);
		vector<int> src2, sink2;
		for (auto x : src) if (special[x]) src2.pb(x);
		for (auto x : src) if (special[x] == 0) src2.pb(x);
		for (auto x : sink) if (special[x]) sink2.pb(x);
		for (auto x : sink) if (special[x] == 0) sink2.pb(x);
		src = src2, sink = sink2;
		if (sz(src) <= sz(sink)) {
			for (int i = 0; i < sz(src); ++i) edg.emplace_back(repr[sink[i]], repr[src[i]]);
			for (int i = sz(src); i < sz(sink); ++i) edg.emplace_back(repr[sink[i]], repr[src[rnd(0, sz(src)-1)]]);
		} else {
			for (int i = 0; i < sz(sink); ++i) edg.emplace_back(repr[sink[i]], repr[src[i]]);
			for (int i = sz(sink); i < sz(src); ++i) edg.emplace_back(repr[sink[rnd(0, sz(sink)-1)]], repr[src[i]]);
		}
		recalc();
		cnt = accumulate(all(exist), 0);
		if (cnt == 1) {
			cout << sz(ans) + k << endl;
			for (auto [x, y] : ans) cout << x+1 << ' ' << y+1 << endl;
			for (int i = 0; i < k; ++i) cout << end(edg)[-1-i].first+1 << ' ' << end(edg)[-1-i].second+1 << endl;
			return;
		}
		for (int i = 0; i < k; ++i) edg.pop_back();
	}
}
 
int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
