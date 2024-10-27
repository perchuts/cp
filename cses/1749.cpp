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
 
int seg[4 * maxn], v[maxn];
 
void build(int i, int l, int r) {
      if (l == r) {
            seg[i] = 1;
            return;
      }
      int md = (l + r) / 2;
      build(2*i, l, md), build(2*i+1, md+1, r);
      seg[i] = r - l + 1;
}
 
int query(int i, int l, int r, int x) {
      --seg[i];
      if (l == r) return v[l];
      int md = (l + r) / 2;
      if (seg[2*i] < x) return query(2*i+1, md+1, r, x - seg[2*i]);      
      return query(2*i, l, md, x);
}
 
int32_t main(){_
      int n; cin >> n;
      for (int i = 1; i <= n; ++i) cin >> v[i];
      build(1, 1, n);
      for (int i = 1; i <= n; ++i) {
            int k; cin >> k;
            cout << query(1, 1, n, k) << " \n"[i==n];
      }
}
