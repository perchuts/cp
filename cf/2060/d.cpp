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

void solve(){
	int n; cin >> n;

	vector<int> a(n);
	for (auto &i : a) cin >> i;

	vector<int> sorted(n);
	sorted[n - 1] = true;
	for (int i = n - 2; i >= 0; i--) {
		sorted[i] = (a[i] <= a[i + 1]) && sorted[i + 1];
	}

	bool ok = sorted[0];
	int d = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < d) break;
		d = a[i] - d;
		ok |= i + 1 == n || (d <= a[i + 1] && sorted[i + 1]);
	}

	cout << (ok ? "YES" : "NO") << endl;
}

int32_t main(){_
  int t = 1; cin >> t;
  while(t--) solve();
}
