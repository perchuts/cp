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
// Euler Path / Euler Cycle
//
// Para declarar: 'euler<true> E(n);' se quiser
// direcionado e com 'n' vertices
// As funcoes retornam um par com um booleano
// indicando se possui o cycle/path que voce pediu,
// e um vector de {vertice, id da aresta para chegar no vertice}
// Se for get_path, na primeira posicao o id vai ser -1
// get_path(src) tenta achar um caminho ou ciclo euleriano
// comecando no vertice 'src'.
// Se achar um ciclo, o primeiro e ultimo vertice serao 'src'.
// Se for um P3, um possiveo retorno seria [0, 1, 2, 0]
// get_cycle() acha um ciclo euleriano se o grafo for euleriano.
// Se for um P3, um possivel retorno seria [0, 1, 2]
// (vertie inicial nao repete)
//
// O(n+m)

template<bool directed=false> struct euler {
	int n;
	vector<vector<pair<int, int>>> g;
	vector<int> used;

	euler(int n_) : n(n_), g(n) {}
	void add(int a, int b) {
		int at = used.size();
		used.push_back(0);
		g[a].emplace_back(b, at);
		if (!directed) g[b].emplace_back(a, at);
	}
#warning chamar para o src certo!
	pair<bool, vector<pair<int, int>>> get_path(int src) {
		if (!used.size()) return {true, {}};
		vector<int> beg(n, 0);
		for (int& i : used) i = 0;
		// {{vertice, anterior}, label}
		vector<pair<pair<int, int>, int>> ret, st = {{{src, -1}, -1}};
		while (st.size()) {
			int at = st.back().first.first;
			int& it = beg[at];
			while (it < g[at].size() and used[g[at][it].second]) it++;
			if (it == g[at].size()) {
				if (ret.size() and ret.back().first.second != at)
					return {false, {}};
				ret.push_back(st.back()), st.pop_back();
			} else {
				st.push_back({{g[at][it].first, at}, g[at][it].second});
				used[g[at][it].second] = 1;
			}
		}
		if (ret.size() != used.size()+1) return {false, {}};
		vector<pair<int, int>> ans;
		for (auto i : ret) ans.emplace_back(i.first.first, i.second);
		reverse(ans.begin(), ans.end());
		return {true, ans};
	}
	pair<bool, vector<pair<int, int>>> get_cycle() {
		if (!used.size()) return {true, {}};
		int src = 0;
		while (!g[src].size()) src++;
		auto ans = get_path(src);
		if (!ans.first or ans.second[0].first != ans.second.back().first)
			return {false, {}};
		ans.second[0].second = ans.second.back().second;
		ans.second.pop_back();
		return ans;
	}
};
void solve(){
 	int n, m; cin >> n >> m;
	euler<true> e(n);
	vector<ii> edg(m);
	for (auto& [x, y] : edg) {
		cin >> x >> y;
		--x, --y;
		e.add(x, y);
	}
	auto [can, ans] = e.get_path(0);
	if (!can or ans.back().first != n-1) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		for (int i = 0; i < sz(ans); ++i) cout << ans[i].first + 1 << ' ';
		cout << endl;
	}
}		

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
