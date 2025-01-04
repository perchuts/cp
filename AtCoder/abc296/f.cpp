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
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;
	auto sa = a;
	auto sb = b;
	sort(all(sa)), sort(all(sb));
	if (sa != sb) {
		cout << "No" << endl;
		exit(0);
	}
	for (int i = 0; i < n-1; ++i) {
		if (sa[i] == sa[i+1]) {
			cout << "Yes" << endl;
			exit(0);
		}
	}
	auto cyc_cnt = [&] (vector<int> v) {
		vector<int> vis(n);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (vis[i]) continue;
			ans ^= 1;
			int cur = i;
			while (vis[cur] == 0) vis[cur] = 1, cur = v[cur] - 1;
		} 
		return ans;
	};
	cout << (cyc_cnt(a) == cyc_cnt(b) ? "Yes" : "No") << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
