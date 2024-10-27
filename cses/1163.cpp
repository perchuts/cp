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
const int maxn = 1e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
int v[maxn];
 
int main(){_
    int x,n;cin>>x>>n;
    set<pair<int,ii>>s;//resposta, intervalo
    set<ii>s2;//resposta, intervalo
    s.insert({x+1,{x,0}}), s2.insert({x,0});
    for(int i=1;i<=n;++i){
        int y;cin>>y;
        auto it = s2.lower_bound({y,0});
        auto [r,l] = *it;
        if(y!=l)s.insert({y-l+(((y-1)!=x)&&l),{y-1,l}}),s2.insert({y-1,l});
        if(r!=y)s.insert({r-y+(r!=x),{r,y+1}}),s2.insert({r,y+1});
        s2.erase(it), s.erase({r-l+1+(r!=x&&l),{r,l}});
        cout<<(*(prev(end(s)))).first<<" ";
    }
 
}
