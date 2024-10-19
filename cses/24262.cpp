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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int solve(int a, int b, int n, vector<ii> v) {
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

int32_t main(){_
	int a, b, n; cin >> a >> b >> n;
	vector<ii> v(n);
	for (auto& [x, y] : v) cin >> x >> y;
	cout << solve(a, b, n, v) << endl;
}
