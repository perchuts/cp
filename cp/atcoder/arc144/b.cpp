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

void solve(){
 	int n, a, b; cin >> n >> a >> b;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	int l = 1, r = 1e10, ans = 1;
	while (l <= r) {
		int md = l + (r-l+1)/2;
		int cnt = 0;
		for (auto x : v) {
			if (x <= md) cnt -= (md-x+a-1)/a;
			else cnt += (x-md)/b;
		}
		if (cnt >= 0) ans = md, l = md + 1;
		else r = md-1;
	}
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
