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
 
int add(int a, int b) {
      if (b >= 1e18 + 1 - a) return 2e18;
      else return a + b;
}
 
int32_t main(){_
      int q; cin >> q;
 
      auto qnt = [] (int x) {
            int tot = 0, pot = 1, qnt = 1;
            while (x >= 10 * pot) {
                  int w = 9 * pot * qnt;
                  tot = add(tot, w);
                  if (tot == 2e18) return tot;
                  pot *= 10, qnt++;
            }
            tot = add(tot, (x - pot + 1) * qnt);
            return tot;
      };
 
      while (q--) {
            int l = 1, r = 1e18, ans = 1;
            int k; cin >> k;
            
            while (l <= r) {
                  int md = l + (r-l+1)/2;
                  if (qnt(md) >= k) ans = md, r = md - 1;
                  else l = md + 1;
            }
 
            int x = qnt(ans), cur = ans;
 
            while (x != k) {
                  cur /= 10, x--;
            }
 
            cout << cur % 10 << endl;
      }
}
