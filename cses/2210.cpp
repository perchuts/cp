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

int fexp(int b, int e) {
	int ans = 1;
	while (e) {
		if (e&1) ans = ans * b % mod;
		e /= 2, b = b * b % mod;
	}
	return ans;
}

void solve(){
 	int n; cin >> n;
	int mod4 = (mod+1)/4;
	if (n == 1) {
		cout << 2 << endl;
		exit(0);
	}
	if (n&1) {
		cout << (fexp(2, n*n) + fexp(2, n*n/4+2) + fexp(2, n*n/2+1)) * mod4 % mod << endl;
	} else {
		cout << (fexp(2, n*n) + fexp(2, n*n/4+1) + fexp(2, n*n/2)) * mod4 % mod << endl;	
	}
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
