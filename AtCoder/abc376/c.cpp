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
	vector<int> a(n), b(n-1);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;
	int l = 1, r = 2e9, ans = -1;
	sort(all(a));
	auto possible = [&] (int k) {
		auto B = b;
		B.pb(k);
		sort(all(B));
		for (int i = 0; i < n; ++i) if (B[i] < a[i]) return false;
		return true;
	};
	while (l <= r) {
		int md = l + (r-l+1)/2;
		if (possible(md)) ans = md, r = md-1;
		else l = md+1;
	}
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
