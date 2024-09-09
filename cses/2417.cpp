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
const int maxn = 1e6+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

void solve(){
 	int n; cin >> n;
	vector<int> v(n), freq(maxn), foi(maxn);
	for (auto& x : v) cin >> x, freq[x]++;
	int ans = n * (n-1) / 2;
	for (int i = maxn-1; i > 1; --i) {
		int tot = 0, tot_foi = 0;
		for (int j = i; j < maxn; j += i) tot_foi += foi[j], tot += freq[j];
		foi[i] = tot * (tot-1) / 2 - tot_foi;
		ans -= foi[i];
	}
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
