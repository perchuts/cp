#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define int long long
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
 
const int inf = 2e9+1;
const int mod = (119<<23)+1;
const int MAX = 1e6+1;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
void solve(){
	int n; cin >> n;
    vector<vector<int>> v(2, vector<int>(n));
    for (auto& x : v) for (auto& y : x) cin >> y;
    
    int ans = 0, a = 0, b = 0;
    for (int i = 1; i <= n; ++i) {
        a += v[0][i-1];
        b += v[1][i-1];
        if (max(a, b) <= i or i <= min(a, b)) {
        } else if (a < i) {
            int s = a+b, f = min(b-i, i-a);
            a += f, b -= f, ans += f;
        } else {
            int s = a+b, f = min(a-i, i-b);
            b += f, a -= f, ans += f;
        }
        ans += abs(a-i) + abs(b-i);
        //cout << a << ' ' << b << ' ' << ans << endl;
    }
    cout << ans << endl;
}
 
int32_t main(){_
  int t = 1;
  while(t--) solve();
}
