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
// Order Statistic Set
//
// Funciona do C++11 pra cima

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
	
// para declarar:
// ord_set<int> s;
// coisas do set normal funcionam:
// for (auto i : s) cout << i << endl;
// cout << s.size() << endl;
// k-esimo maior elemento O(log|s|):
// k=0: menor elemento
// cout << *s.find_by_order(k) << endl;
// quantos sao menores do que k O(log|s|):
// cout << s.order_of_key(k) << endl;

// Para fazer um multiset, tem que
// usar ord_set<pair<int, int>> com o
// segundo parametro sendo algo para diferenciar
// os ementos iguais.
// s.order_of_key({k, -INF}) vai retornar o
// numero de elementos < k
ll solve(int a, int b, int n, vector<ii> v) {
	ord_set<iii> s;	
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
ll solve2(int a, int b, int n, vector<ii> v) {
#define int ll
	vector<int> choice(a+b);
	iota(all(choice), 0);
	auto calc = [&] (vector<int> c) {
		assert(sz(c) == a+b);
		vector<int> ord(a+b);
		iota(all(ord), 0);
		sort(all(ord), [&] (int x, int y) {
			int xx = v[c[x]].second - v[c[x]].first;
			int yy = v[c[y]].second - v[c[y]].first;
			if (xx == yy) return v[c[x]].second > v[c[x]].second;
			return xx > yy;
		});
		int tot = 0;
		for (int i = 0; i < a+b; ++i) {
			if (i < b) tot += v[c[ord[i]]].second;
			else tot += v[c[ord[i]]].first;
		}
		return tot;
	};
	for (int i = a + b; i < n; ++i) {
		choice.pb(i);
		vector<int> ord(a+b+1);
		iota(all(ord), 0);
		sort(all(ord), [&] (int x, int y) {
			int xx = v[choice[x]].second - v[choice[x]].first;
			int yy = v[choice[y]].second - v[choice[y]].first;
			if (xx == yy) return v[choice[x]].second > v[choice[y]].second;
			return xx > yy;
		});
		int mA = -1, valA = 1e18, mB = -1, valB = 1e18;
		for (int j = 0; j <= a+b; ++j) {
			if (j < b) {
				if (ckmin(valB, v[choice[ord[j]]].second)) mB = j;
			} else {
				if (ckmin(valA, v[choice[ord[j]]].first)) mA = j;
			}
		}
		vector<int> c1, c2;
		for (int j = 0; j <= a+b; ++j) {
			if (mA != j) c1.pb(choice[ord[j]]);
			if (mB != j) c2.pb(choice[ord[j]]);
		}
		if (calc(c1) <= calc(c2)) choice = c2;
		else choice = c1;
	}
	return calc(choice);
}
#define int int32_t
int32_t main(){_
	int ttt = 1;
	while (true) {
		const int lim = 10;
		const int limVal = 1000;
		int a = rnd(1, lim), b = rnd(1, lim);
		int n = rnd(a+b, a+b+lim);
		vector<ii> v(n);
		for (auto& [x, y] : v) x = rnd(1, limVal), y = rnd(1, limVal);
		int best = solve2(a, b, n, v);
		int my = solve(a, b, n, v);
		if (my != best) {
			cout << "Wrong answer on test " << ttt << endl;
			cout << a << ' ' << b << ' ' << n << endl;
			for (auto x : v) cout << x.first << " " << x.second << endl;
			cout << endl;
			cout << "Answer: " << best << endl;
			cout << "Your solution: " << my << endl;
			exit(0);
		}
		cout << "Accepted on test " << ttt++ << endl;
	}
}
