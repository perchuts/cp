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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
	
ll solve(int a, int b, int n, vector<ii> v) {
	ord_set<iii> s;	
	if (a == 0 and b == 0) return 0;
	ll totA = 0, totB = 0;
	for (int i = 0; i < a+b; ++i) s.insert({v[i].first - v[i].second, -v[i].second, i});
	set<ii> art, prog;
	for (int i = 0; i < a+b; ++i) {
		int pos = s.order_of_key({v[i].first - v[i].second, -v[i].second, i});
		if (pos < b) art.insert({v[i].second, i}), totB += v[i].second;
		else prog.insert({v[i].first, i}), totA += v[i].first;
	}
	for (int i = a + b; i < n; ++i) {
		s.insert({v[i].first - v[i].second, -v[i].second, i});
		// achei o indice dele 
		int pos = s.order_of_key({v[i].first - v[i].second, -v[i].second, i});
		if (pos < b) {
			totB += v[i].second;	
			art.insert({v[i].second, i});
			if (a) {
				auto [x, y, z] = *s.find_by_order(b);
				totA += v[z].first, totB -= v[z].second;
				prog.insert({v[z].first, z});
				art.erase({v[z].second, z});
			}
		} else {
			totA += v[i].first;
			prog.insert({v[i].first, i});
		}
		ll val1 = -1, val2 = -1;
		int z = -1;
		if (b) {
			auto it = begin(art);
			if (a) {
				auto [x, y, Z] = *s.find_by_order(b);
				z = Z;
				val1 = totA + totB - it->first - v[z].first + v[z].second;
			} else {
				val1 = totA + totB - it->first;
			}
		}
		if (a) {
			auto it2 = begin(prog);
			val2 = totA + totB - it2->first;
		}
		if (val1 >= val2) {
			auto it = begin(art);
			int id = (it->second);
			totB -= it->first;
			if (z != -1) {
				totA -= v[z].first, prog.erase({v[z].first, z});
				totB += v[z].second, art.insert({v[z].second, z});
			}
			s.erase({v[id].first - v[id].second, -v[id].second, id});
			art.erase({it->first, it->second});
		} else {
			auto it = begin(prog);
			totA -= it->first;
			int id = (it->second);
			s.erase({v[id].first - v[id].second, -v[id].second, id});
			prog.erase({it->first, it->second});
		}
	}
	return totA + totB;
}

int32_t main(){_
	int a, b, n; cin >> a >> b >> n;
	vector<ii> v(n);
	for (auto& [x, y] : v) cin >> x >> y;
	cout << solve(a, b, n, v) << endl;
}
