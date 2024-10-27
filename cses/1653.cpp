#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
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
 
int32_t main(){_
      int n, x; cin >> n >> x;
      if (n == 1) {
            cout << 1 << endl;
            return 0;
      }
      vector<int> v(n);
      for (auto& x : v) cin >> x;
      vector<ii> dp((1<<n)); dp[0].second = x;
      for (int i = 1; i < (1 << n); ++i) {
            dp[i] = {inf, inf};
            for (int j = 0; j < n; ++j) {
                  if ((i >> j) & 1) {
                        int k = i - (1 << j);
                        if (dp[k].second + v[j] <= x) {
                              ckmin(dp[i], make_pair(dp[k].first, dp[k].second + v[j]));
                        } else {
                              ckmin(dp[i], make_pair(dp[k].first+1, min(dp[k].second, v[j])));
                        }
                  }
            }
      }
      cout << dp[(1<<n)-1].first << endl;
}
