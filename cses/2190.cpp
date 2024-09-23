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
	pt p1, p2, p3, p4; cin >> p1 >> p2 >> p3 >> p4;
	auto get_side = [&] (pt a, pt b, pt c) {
		ll sgn = (b-a) ^ (c-a);
		return sgn < 0;
	};
	auto inter = [&] (pt a, pt b, pt c) {
		ll sgn = (b-a) ^ (c-a);
		return (sgn == 0 and 0 <= (b-a) * (c-a) and (b-a)*(c-a) <= (b-a) * (b-a));
	};
	int ok = 0;
	ok |= inter(p1, p2, p3);
	ok |= inter(p1, p2, p4);
	ok |= inter(p3, p4, p1);
	ok |= inter(p3, p4, p2);
	if ((get_side(p1, p2, p3) != get_side(p1, p2, p4) and get_side(p3, p4, p1) != get_side(p3, p4, p2)) or ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int32_t main(){_
  int t; cin >> t;
  while(t--) solve();
}
