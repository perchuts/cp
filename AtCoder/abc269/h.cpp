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
const int mod = (119<<23)+1;
const int maxn = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
// Aritmetica Modular
//
// O mod tem q ser primo

template<int p> struct mod_int {
	ll expo(ll b, ll e) {
		ll ret = 1;
		while (e) {
			if (e % 2) ret = ret * b % p;
			e /= 2, b = b * b % p;
		}
		return ret;
	}
	ll inv(ll b) { return expo(b, p-2); }

	using m = mod_int;
	int v;
	mod_int() : v(0) {}
	mod_int(ll v_) {
		if (v_ >= p or v_ <= -p) v_ %= p;
		if (v_ < 0) v_ += p;
		v = v_;
	}
	m& operator +=(const m& a) {
		v += a.v;
		if (v >= p) v -= p;
		return *this;
	}
	m& operator -=(const m& a) {
		v -= a.v;
		if (v < 0) v += p;
		return *this;
	}
	m& operator *=(const m& a) {
		v = v * ll(a.v) % p;
		return *this;
	}
	m& operator /=(const m& a) {
		v = v * inv(a.v) % p;
		return *this;
	}
	m operator -(){ return m(-v); }
	m& operator ^=(ll e) {
		if (e < 0) {
			v = inv(v);
			e = -e;
		}
		v = expo(v, e);
		// possivel otimizacao:
		// cuidado com 0^0
		// v = expo(v, e%(p-1)); 
		return *this;
	}
	bool operator ==(const m& a) { return v == a.v; }
	bool operator !=(const m& a) { return v != a.v; }

	friend istream& operator >>(istream& in, m& a) {
		ll val; in >> val;
		a = m(val);
		return in;
	}
	friend ostream& operator <<(ostream& out, m a) {
		return out << a.v;
	}
	friend m operator +(m a, m b) { return a += b; }
	friend m operator -(m a, m b) { return a -= b; }
	friend m operator *(m a, m b) { return a *= b; }
	friend m operator /(m a, m b) { return a /= b; }
	friend m operator ^(m a, ll e) { return a ^= e; }
};

// NTT
//
// Precisa do mint (primitivas de aritmetica modular)
//
// O(n log (n))

const int MOD = 998244353;
typedef mod_int<MOD> mint;

void ntt(vector<mint>& a, bool rev) {
	int n = a.size(); auto b = a;
	assert(!(n&(n-1)));
	mint g = 1; 
	while ((g^(MOD / 2)) == 1) g += 1;
	if (rev) g = 1 / g;

	for (int step = n / 2; step; step /= 2) {
		mint w = g^(MOD / (n / step)), wn = 1;
		for (int i = 0; i < n/2; i += step) {
			for (int j = 0; j < step; j++) {
				auto u = a[2 * i + j], v = wn * a[2 * i + j + step];
				b[i+j] = u + v; b[i + n/2 + j] = u - v;
			}
			wn = wn * w;
		}
		swap(a, b);
	}
	if (rev) {
		auto n1 = mint(1) / n;
		for (auto& x : a) x *= n1;
	}
}

vector<mint> convolution(const vector<mint>& a, const vector<mint>& b) {
	vector<mint> l(a.begin(), a.end()), r(b.begin(), b.end());
	int N = l.size()+r.size()-1, n = 1;
	while (n <= N) n *= 2;
	l.resize(n);
	r.resize(n);
	ntt(l, false);
	ntt(r, false);
	for (int i = 0; i < n; i++) l[i] *= r[i];
	ntt(l, true);
	l.resize(N);
	return l;
}

void solve(){
    int n; cin >> n;
    vector<int> p(n), subt(n);
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) cin >> p[i], --p[i], g[p[i]].pb(i);
    vector<vector<vector<mint>>> h(n);
    vector<vector<mint>> f(n);
    auto pre = [&] (auto&& self, int u) -> void {
        subt[u] = 1;
        for (auto v : g[u]) {
            self(self, v);
            subt[u] += subt[v];
        }
    };
    pre(pre, 0);
    auto dfs = [&] (auto&& self, int u, bool is_light) -> void {
        int id = -1, t = 0;
        for (auto v : g[u]) if (ckmax(t, subt[v])) id = v;
        if (id != -1) {
            self(self, id, 0);
            swap(h[u], h[id]);
        }
        priority_queue<ii> pq;
        for (auto v : g[u]) {
            if (v == id) continue;
            self(self, v, 1);
            pq.push({-sz(f[v]), v}); 
        }
        f[u] = {1};
        pq.push({-1, u});
        while (sz(pq) > 1) {
            auto [x1, y1] = pq.top(); pq.pop();
            auto [x2, y2] = pq.top(); pq.pop();
            f[min(y1, y2)] = convolution(f[y1], f[y2]);
            pq.push({-sz(f[min(y1, y2)]), min(y1, y2)});
        }
        h[u].pb(f[u]);
        if (is_light == false) return;
        auto work = [&] (auto&& self, int l, int r) -> pair<vector<mint>, vector<mint>> {
            if (l == r) return make_pair(vector<mint>(1, 1), h[u][l]);
            int md = (l+r)/2;
            auto [a, b] = self(self, l, md);
            auto [c, d] = self(self, md+1, r);
            auto bc = convolution(b, c);
            auto bd = convolution(b, d);
            if (sz(a) < sz(bc)) a.resize(sz(bc));
            for (int i = 0; i < sz(a); ++i) a[i] += bc[i];
            return make_pair(a, bd);
        };
        reverse(all(h[u]));
        auto [a, b] = work(work, 0, sz(h[u])-1);
        f[u] = vector<mint>(max(sz(a)+1, sz(b)), 0);
        for (int i = 0; i < sz(a); ++i) f[u][i+1] += a[i];
        for (int i = 0; i < sz(b); ++i) f[u][i] += b[i];
    };
    dfs(dfs, 0, 1);
    for (int i = 1; i <= n; ++i) cout << (i < sz(f[0]) ? f[0][i] : 0) << endl;
}

int32_t main(){_
    int t = 1; //cin >> t;
    while(t--) solve();
}
