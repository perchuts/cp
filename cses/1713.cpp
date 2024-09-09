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

int divs[maxn], prim[maxn];

void solve(){
 	int x; cin >> x;
	cout << divs[x] << endl;
}

int32_t main(){_
  int t = 1; cin >> t;
  divs[1] = 1;
  for (int i = 2; i < maxn; ++i) {
	if (prim[i]) continue;
	prim[i] = i;
	for (int j = i * i; j < maxn; j += i) {
		if (prim[j] == 0) prim[j] = i;
	}
  }
  for (int i = 2; i < maxn; ++i) {
	  int cur = i, cnt = 1;
	  while (cur % prim[i] == 0) cnt++, cur /= prim[i];
	  divs[i] = divs[cur] * cnt;
  }
  while(t--) solve();
}
