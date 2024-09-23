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


int32_t main(){_
	int t = 10;
	while (t--) {
		int n = rnd(1, 5);
		string s;
		for (int i = 0; i < n; ++i) s.pb(char('a' + rnd(0, 5)));
		s += "#";
		vector<int> v(n+1);
		iota(all(v), 0);
		sort(all(v), [&] (int a, int b) {
			for (int i = 0; ; ++i) {
				if (s[a+i] != s[b+i]) return s[a+i] < s[b+i];
			}
			return false;
		});
		cout << s << endl;
		for (auto x : v) cout << x << ' ';
		cout << endl;
		for (auto x : v) cout << s[(x+n)%(n+1)];
		cout << endl;
		cout << endl << endl;
	}
}
