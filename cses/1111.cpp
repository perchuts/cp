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
 
vector<int> manacher(string s) {
      int n = sz(s);
      s = '$' + s + '^';
      vector<int> v(n + 1);
      int l = 1, r = 1;
      for (int i = 1; i <= n; ++i) {
            v[i] = max(0ll, min(r - i, v[l + r - i]));
            while (s[i-v[i]] == s[i+v[i]]) v[i]++;
            if (r < i+v[i]) r = i + v[i], l = i - v[i]; 
      }
      return vector<int>(begin(v)+1, end(v)-1);
}
 
int32_t main(){_
      string s; cin >> s;
      int ans = 0, n = sz(s), c = 0;
      string s2;
      for (auto x : s) s2 += '#', s2 += x;
      vector<int> p = manacher(s2 + '#');
      for (int i = 0; i < n; ++i) {
            if (ckmax(ans, max(p[2*i], p[2*i+1])-1)) c = i;
      }
      for (int i = c - ans/2; i <= c + ans/2 - (ans%2==0); ++i) cout << s[i];
}
