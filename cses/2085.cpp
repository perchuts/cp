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

const int LINF = 1e18;
const int mod = 1e9+7;
const int maxn = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

// Convex Hull Trick Dinamico
//
// para double, use LINF = 1/.0, div(a, b) = a/b
// update(x) atualiza o ponto de intersecao da reta x
// overlap(x) verifica se a reta x sobrepoe a proxima
// add(a, b) adiciona reta da forma ax + b
// query(x) computa maximo de ax + b para entre as retas
//
// O(log(n)) amortizado por insercao
// O(log(n)) por query

struct Line {
	mutable ll a, b, p;
	bool operator<(const Line& o) const { return a < o.a; }
	bool operator<(ll x) const { return p < x; }
};

struct dynamic_hull : multiset<Line, less<>> {
	ll div(ll a, ll b) {
		return a / b - ((a ^ b) < 0 and a % b);
	}

	void update(iterator x) {
		if (next(x) == end()) x->p = LINF;
		else if (x->a == next(x)->a) x->p = x->b >= next(x)->b ? LINF : -LINF;
		else x->p = div(next(x)->b - x->b, x->a - next(x)->a);
	}

	bool overlap(iterator x) {
		update(x);
		if (next(x) == end()) return 0;
		if (x->a == next(x)->a) return x->b >= next(x)->b;
		return x->p >= next(x)->p;
	}

	void add(ll a, ll b) {
		auto x = insert({a, b, 0});
		while (overlap(x)) erase(next(x)), update(x);
		if (x != begin() and !overlap(prev(x))) x = prev(x), update(x);
		while (x != begin() and overlap(prev(x)))
			x = prev(x), erase(next(x)), update(x);
	}

	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
#warning cuidado com overflow!
		return l.a * x + l.b;
	}
};

void solve(){
	int n, X; cin >> n >> X;
	vector<int> s(n), f(n);
	for (auto& x : s) cin >> x;
	for (auto& x : f) cin >> x;
	dynamic_hull cht;
	cht.add(-X, 0);
	int ans;
	for (int i = 0; i < n; ++i) {
		ans = cht.query(s[i]);
		cht.add(-f[i], ans);
	}
	cout << -ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
