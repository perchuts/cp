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
using matrix = vector<vector<int>>;
 
const int inf = 2e9+1;
const int mod = 1e9+7;
const int maxn = 1e6 + 100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
void mult(matrix& a, matrix b) {
      int n = sz(a);
      matrix ans(n, vector<int>(n));
      for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) 
            ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % mod;
      swap(a, ans);
}
 
matrix fexp(matrix a, int k) {
      int n = sz(a);
      matrix ans(n, vector<int>(n)), p = a;
      for (int i = 0; i < n; ++i) ans[i][i] = 1;
      while (k) {
            if (k&1) mult(ans, p);
            mult(p, p);
            k /= 2;
      }
      return ans;
}
 
int32_t main(){_
      // O(1) memory, O(t * logn) time
      int t; cin >> t;
      while(t--) {
            int n; cin >> n;
            matrix m = fexp({{2, 1}, {1, 4}}, n-1);            
            cout << (m[0][0] + m[0][1] + m[1][0] + m[1][1]) % mod << endl;
      }
}
