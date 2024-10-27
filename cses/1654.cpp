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
 
int v[maxn], ans[4*maxn], f[4*maxn], g[4*maxn];
 
int32_t main(){_
      int n; cin >> n;
      for (int i = 1; i <= n; ++i) cin >> v[i], f[v[i]]++, g[v[i]]++;
      for (int j = 0; j < 20; ++j) {
            for (int i = (1 << 20) - 1; i >= 0; --i) {
                  if ((i >> j) & 1) f[i] += f[i ^ (1 << j)], g[i ^ (1<<j)] += g[i];
            }
      }
      //submasks are calculated; now what
      //calculate supermasks
      for (int i = 1; i <= n; ++i) {
            int notmee = ((1 << 20) - 1) & ~v[i];
            cout << f[v[i]] << ' ' << g[v[i]] << ' ' << n - f[notmee] << endl;
      }
 
}
