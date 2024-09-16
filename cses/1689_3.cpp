#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;

const int inf = 2e9+1;
const int mod = 1e9+7;
const int n = 8;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
      uniform_int_distribution<int> uid(l, r);
      return uid(rng);
}

double rnd_d(double l, double r) {
      uniform_real_distribution<double> uid(l, r);
      return uid(rng);
}

vector<int> g[64];
int vmask[64];

const double a = 0.99999;

double last = 1e9;

double temperature() { return last *= a; }

int id(int x, int y) {
	return n*x+y;
}

struct state {
	int vis;
	vector<int> path;
};

void go(state& s) {
	int u = s.path.back();
	vector<int> possible;
	int best = 6969;
	for (auto v : g[u]) {
		if ((s.vis>>v)&1) continue;
		int unreached = vmask[v] - (s.vis&vmask[v]);
		if (ckmin(best, __builtin_popcountll(unreached))) possible = {v};
		else if (best == __builtin_popcountll(unreached)) possible.pb(v);
	}
	if (possible.empty()) return;
	int x = rnd(0, sz(possible)-1);
	s.vis += (1LL << possible[x]);
	s.path.pb(possible[x]);
	go(s);
}

bool change(int x, int y, double t) {
      if (y > x) return true;
      double p = exp((y - x) / t), k = rnd_d(0, 1);
      return p >= k;
}

void init() {
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		vector<int> mov = {2, 1};
		for (int xx = 0; xx < 2; ++xx) {
			for (auto yy = 0; yy < 2; ++yy) {
				for (auto zz = 0; zz < 2; ++zz) {
					int i2 = i + mov[0], j2 = j + mov[1];
					if (min(i2, j2) >= 0 && max(i2, j2) < n) g[n*i+j].pb(n*i2+j2), vmask[n*i+j] |= (1LL<<id(i2, j2));
					mov[0] *= -1;	
				}
				mov[1] *= -1;
			}
			swap(mov[0], mov[1]);
		}
	}
}

int32_t main(){_
	init();
	int stx, sty; cin >> stx >> sty; --stx, --sty;
	swap(stx, sty);
	state sol;
	sol.vis += (1LL<<id(stx, sty));
	sol.path.pb(id(stx, sty));
	int my_score = 0, tt = 0;
	auto score = [] (state z) {
		int ini = sz(z.path);
		//for (auto x : z.path) if (x / 8 == 0 || x / 8 == 7 || x % 8 == 0 || x % 8 == 7) ini += 2;
		return ini;
	};
	while (my_score != n * n) {
		tt++;
		state s;
		s.vis = (1LL<<id(stx, sty));
		s.path.pb(id(stx, sty));
		go(s);
		if (ckmax(my_score, score(s))) sol = s;
	}
	cout << tt << endl;
	vector grid(n, vector(n, -1));
	for (int i = 1; i <= sz(sol.path); ++i) {
		int x = sol.path[i-1]/n, y = sol.path[i-1] % n;
		grid[x][y] = i;
	}
	for (auto x : grid) {
		for (auto y : x) cout << y << ' ';
		cout << endl;
	}
}
