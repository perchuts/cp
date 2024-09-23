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


struct pt { // ponto
	int x, y;
	pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

void solve(){
	int n, m; cin >> n >> m;
 	vector<pt> p(n); 
	for (auto& x : p) cin >> x;
	auto inter = [&] (pt a, pt b, pt c) {
		ll sgn = (b-a) ^ (c-a);
		return (sgn == 0 and 0 <= (b-a) * (c-a) and (b-a)*(c-a) <= (b-a) * (b-a));
	};
	ll area = 0;
	for (int i = 0; i < n; ++i) {
		area += (p[i].y + p[(i+1)%n].y) * (p[i].x - p[(i+1)%n].x);
	}
	area = abs(area);
	for (int __ = 0; __ < m; ++__) {
		pt point; cin >> point;
		bool ok = 0;
		for (int i = 0; i < n; ++i) {
			if (inter(p[i], p[(i+1)%n], point)) ok = 1;	
		}
		if (ok) {
			cout << "BOUNDARY" << endl;
			continue;
		}
		// como o poligono eh nao convexo, n da pra fazer coisas com areas
		int tot = 0;
		for (int i = 0; i < n; ++i) {
			pt a = p[i], b = p[(i+1)%n];
			if (a.x == b.x) continue;
			// vou atirar pra baixo nessa porra
			int x1 = (a.x < point.x);
			int x2 = (b.x < point.x);
			if (x1 == x2) continue;
			int sgn = (b-a)^(point-a);
			// se sgn > 0, ent o ponto ta a esquerda de AB
			// se A ta em cima de B, ent queremos q
			if ((sgn > 0) == x1) tot++;
		}
		cout << (tot % 2 ? "INSIDE" : "OUTSIDE") << endl;
	}
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
