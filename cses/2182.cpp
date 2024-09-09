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
	int tot_div = 1, tot_sum = 1, tot_prod = 1, tot_div2 = 1;
	vector<ii> v(n);
	for (auto& [p, vp] : v) { 
		cin >> p >> vp;
		int G = (fexp(p, vp+1)+mod-1) * fexp(p-1, mod - 2) % mod;
		tot_sum = tot_sum * G % mod;
		tot_div = tot_div * (vp + 1) % mod;
		int e = vp*(vp+1)/2%(mod-1);
		tot_prod = fexp(tot_prod, vp+1) * fexp(p, e*tot_div2) % mod;
		tot_div2 = tot_div2 * (vp + 1) % (mod-1);
	}
	cout << tot_div << ' ' << tot_sum << ' ' << tot_prod << endl;
}
 
 
int32_t main(){_
  int t = 1; 
  while(t--) solve();
}
