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
 
int main(){_
    int n;cin>>n;
    set<int>s;
    for(int i=1;i<=n;++i){
        s.insert(i);
    }
    int inc = 2, primeiro = 0;
    while(!s.empty()){
        if(sz(s)==1){
            cout<<(*begin(s))<<" ";
            return 0;
        }
        int cur = (primeiro?(*begin(s)):(*next(begin(s))));
        while(cur<=n){
            cout<<cur<<" ";
            s.erase(cur);
            cur += inc;
        }
        auto it = s.lower_bound(cur-inc);
        primeiro = it!=s.end(), inc += inc;
    }
}
