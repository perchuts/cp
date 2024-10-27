#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
 
const int INF = 2e9+1;
const int mod = 1e9+7;
const int maxn = 3e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
// Order Statistic Set
//
// Funciona do C++11 pra cima
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
	
// para declarar:
// ord_set<int> s;
// coisas do set normal funcionam:
// for (auto i : s) cout << i << endl;
// cout << s.size() << endl;
// k-esimo maior elemento O(log|s|):
// k=0: menor elemento
// cout << *s.find_by_order(k) << endl;
// quantos sao menores do que k O(log|s|):
// cout << s.order_of_key(k) << endl;
 
// Para fazer um multiset, tem que
// usar ord_set<pair<int, int>> com o
// segundo parametro sendo algo para diferenciar
// os ementos iguais.
// s.order_of_key({k, -INF}) vai retornar o
// numero de elementos < k
void solve(){
    int n, q; cin >> n >> q;
    vector<int> p(n);
    ord_set<ii> s;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        s.insert(make_pair(p[i], i));
    }
    while (q--) {
        char a; int x, y;
        cin >> a >> x >> y;
        if (a == '?') {
            cout << s.order_of_key(make_pair(y, n)) - s.order_of_key(make_pair(x-1, n)) << endl;
        } else {
            --x;
            s.erase(make_pair(p[x], x));
            p[x] = y;
            s.insert(make_pair(p[x], x));
        }
    }
}
 
int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
