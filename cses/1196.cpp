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

vector<pair<int, ll>> g[maxn];

void solve(){
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		--u, --v;
		g[u].pb({v, w});
	}
	vector<multiset<ll>> dist(n);
	dist[0].insert(0);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push({0, 0});
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (dist[u].find(d) == dist[u].end()) continue;
		for (auto [v, w] : g[u]) {
			ll d2 = d + w;
			auto it = dist[v].lower_bound(d2);
			if (sz(dist[v]) == k) {
				if (it == end(dist[v])) continue;
				else if (*prev(end(dist[v])) > d2) {
					dist[v].insert(d2);
					dist[v].extract(*prev(end(dist[v])));
					pq.push({d2, v});
				}
			} else {
				dist[v].insert(d2);
				pq.push({d2, v});
			}
		}
	}
	for (auto x : dist.back()) cout << x << ' ';
	cout << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
