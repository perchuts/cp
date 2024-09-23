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

int sq(int x) {
	return x * x;
}


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
int dist2(pt a, pt b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}
ll polarea2(vector<pt> v) { // 2 * area do poligono
	ll ret = 0;
	for (int i = 0; i < v.size(); i++)
		ret += sarea2(pt(0, 0), v[i], v[(i + 1) % v.size()]);
	return abs(ret);
}
// Closest pair of points
//
// O(nlogn)

pair<pt, pt> closest_pair_of_points(vector<pt> v) {
	int n = v.size();
	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++) if (v[i] == v[i-1]) return {v[i-1], v[i]};
	auto cmp_y = [&](const pt &l, const pt &r) {
		if (l.y != r.y) return l.y < r.y;
		return l.x < r.x;
	};
	set<pt, decltype(cmp_y)> s(cmp_y);
	int l = 0, r = -1;
	ll d2_min = numeric_limits<ll>::max();
	pt pl, pr;
	const int magic = 5;
	while (r+1 < n) {
		auto it = s.insert(v[++r]).first;
		int cnt = magic/2;
		while (cnt-- and it != s.begin()) it--;
		cnt = 0;
		while (cnt++ < magic and it != s.end()) {
			if (!((*it) == v[r])) {
				ll d2 = dist2(*it, v[r]);
				if (d2_min > d2) {
					d2_min = d2;
					pl = *it;
					pr = v[r];
				}
			}
			it++;
		}
		while (l < r and sq(v[l].x-v[r].x) > d2_min) s.erase(v[l++]);
	}
	return {pl, pr};
}
void solve(){
	int n; cin >> n;
 	vector<pt> p(n); 
	for (auto& x : p) cin >> x;
	auto [a, b] = closest_pair_of_points(p);
	cout << dist2(a, b) << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
