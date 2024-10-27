#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
int solve(int n, vector<int> v, bool mode = 0){
	vector<int> onde(n+1);
	vector<vector<int>> g(n+1);
	for (int i = 0; i < n; ++i) onde[v[i]] = i;
	int ptr = -1, ok = 1;
	vector<int> par(2*n);	
	vector<set<int>> comps(2*n);
	set<int> reprs;
	for (int i = 0; i < 2*n; ++i) par[i] = i;
	for (int i = 0; i < n; ++i) reprs.insert(i), comps[i+n].insert(i);
	auto findp = [&] (auto&& self, int u) -> int {
		return par[u] = (par[u] == u ? u : self(self, par[u]));
	};
	auto merge = [&] (int u, int w) {
		u = findp(findp, u), w = findp(findp, w);
		if (u == w) return;
		if (!comps[u].empty()) reprs.erase(*begin(comps[u]));	
		if (!comps[w].empty()) reprs.erase(*begin(comps[w]));	
		if (sz(comps[u]) < sz(comps[w])) swap(u, w);
		par[w] = u;
		for (auto x : comps[w]) comps[u].insert(x);
		if (!comps[u].empty()) reprs.insert(*begin(comps[u]));
	};
	auto tira = [&] (int x) {
		int p = findp(findp, x+n);
		reprs.erase(*begin(comps[p]));	
		comps[p].erase(x);
		if (!comps[p].empty()) reprs.insert(*begin(comps[p]));
	};
	for (int i = 1; i <= n; ++i) {
		tira(onde[i]);
		if (ptr < onde[i]) {
			ptr = onde[i];
			continue;
		}
		// want to find first element outside my component and merge it w/me
		// this way, we avoid adding unnecessary edges!
		//if (mode) cout << "verificando " << i << endl;
		//if (mode) for (int j = 0; j < 2*n; ++j) cout << findp(findp, j) << ' ';
		//if (mode) cout << endl;
		while (true) {
			auto it = reprs.lower_bound(onde[i]);
			if (it == end(reprs)) break;
			int p = findp(findp, *it+n);
			if (p == findp(findp, onde[i])) it = next(it);
			if (it == end(reprs)) break;
			int x = *it;
			if (x >= ptr) break;
			//if (mode) cout << "separando o " << onde[i] << " do " << x << endl; 
			merge(onde[i], x+n), merge(onde[i]+n, x);
			g[onde[i]].pb(x), g[x].pb(onde[i]);
			if (findp(findp, onde[i]) == findp(findp, onde[i]+n) or findp(findp, x) == findp(findp, x+n)) return -1;
		}
	}
	vector<int> vis(n);
	auto dfs = [&] (auto&& self, int u) -> bool {
		bool bip = 1;
		for (auto w : g[u]) {
			if (vis[w] == 0) {
				vis[w] = 3 - vis[u];
				bip &= self(self, w);
			} else bip &= vis[w] != vis[u]; 
		}
		return bip;
	};
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			vis[i] = 1;
			ok &= dfs(dfs, i);
		}
	}
	if (!ok) return -1;
	vector<int> p1, p2;
	for (int j = 0; j < n; ++j) {
		if (vis[j] == 1) p1.pb(j);
		else p2.pb(j);
	}
	int pt = 0;
	stack<int> st1, st2;
	for (int k = 1; k <= n; ++k) {
		while (pt <= onde[k]) {
			if (vis[pt] == 1) st1.push(v[pt]);
			else st2.push(v[pt]);
			pt++;
		}
		if (!st1.empty() and st1.top() == k) st1.pop();
		else if (!st2.empty() and st2.top() == k) st2.pop();
		else {
			ok = 0; break;
		}
	}
	if (!ok) return -1;
	if (mode == 0) {
		int ans = 0;
		for (int i = 0; i < n; ++i) if (vis[i] == 1) ans += (1 << i);
		return ans;
	}
	for (auto x : vis) cout << x << ' ';
	cout << endl;
	exit(0);
}
 
// wrong idea!
// 1 4 3 5 2
// 2 3 1
// 1 3 2
//
// the idea is still wrong
// Intervals
// numbers with same color must satisfy what?
// their exit times, when ordered, must form a V
// 2 3 1
// R R B
// -> fez o L
// sse? parece que sim!
//
void solve() {
	int n; cin >> n;
	vector<int> p(n);
	for (auto& x : p) cin >> x;
	auto x = solve(n, p, 1);
	if (x == -1) {
		cout << "IMPOSSIBLE" << endl;
		exit(0);
	}
}
 
int32_t main(){_
	int tt = 1;
	solve();
	while (true) {
		int n = rnd(3, 10);
		vector<int> p(n); iota(all(p), 1);
		shuffle(all(p), rng);
		int tot = 0;
		auto check = [&] (int i) {
			vector<int> p1, p2, onde(n+1);
			bool ok = 1;
			for (int j = 0; j < n; ++j) {
				if ((i >> j) & 1) p1.pb(p[j]);
				else p2.pb(p[j]);
				onde[p[j]] = j;
			}
			int pt = 0, deu = ok;
			if (ok) {
				stack<int> st1, st2;
				for (int k = 1; k <= n; ++k) {
					while (pt <= onde[k]) {
						if ((i>>pt)&1) st1.push(p[pt]);
						else st2.push(p[pt]);
						pt++;
					}
					if (!st1.empty() and st1.top() == k) st1.pop();
					else if (!st2.empty() and st2.top() == k) st2.pop();
					else {
						deu = 0; break;
					}
				}
			}
			return deu;
		};
		for (int i = 0; i < (1 << n); ++i) tot += check(i);
		int my = solve(n, p);
		if ((my == -1 and tot != 0) or (my != -1 and check(my) == 0)) {
			cout << "Wrong answer on test " << tt << endl;
			cout << n << endl;
			for (auto x : p) cout << x << ' ';
			cout << endl;
			cout << "Your solution: ";
			if (my == -1) {
				cout << "None" << endl;
				cout << "There is at least one solution :(" << endl;
			} else {
				cout << my << ' ';
				for (int j = 0; j < n; ++j) cout << (((my>>j)&1) ? 1 : 2) << ' ';
				cout << endl;
				if (check(my) == 0) cout << "Your solution is incorrect!" << endl;
			}
			exit(0);	
		}
		cout << "Accepted on test " << tt++;
		if (my == -1) cout << " (-)" << endl;
		else cout << endl;
	}
}
