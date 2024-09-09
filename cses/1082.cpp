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
 	int n; cin >> n;
	int ans = 0, i = 1;
	for ( ; i * i <= n; ++i) ans = (ans + n / i * i) % mod;
	--i;
	int m2 = (mod+1)/2;
	for (int j = n/i; j; --j) {
		int k = n/j;
		if (k > i) {
			int conta = (((k-i)%mod) * ((i+1+k)%mod))%mod*m2%mod*j%mod;
			ans = (ans + conta) % mod, i=k;
		}
	}
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
