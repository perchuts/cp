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
const int maxn = 2e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
int bit[maxn], n;
 
void insert(int x,int d){
    for(;x<=n;x+=x&(-x))ckmax(bit[x],d);
}
 
int query(int x){
    int ans = 0;
    while(x>0){
        ckmax(ans,bit[x]);
        x -= x&(-x);
    }
    return ans;
}
 
int main(){_
    cin>>n;
    vector<int>v(n), tmp;
    for(auto& x:v)cin>>x;
    tmp = v;
    sort(all(tmp)), tmp.erase(unique(all(tmp)),tmp.end());
    int ans = 0;
    for(int i=0;i<n;++i){
        int idx = lower_bound(all(tmp),v[i]) - begin(tmp);
        int best = query(idx+1);
        ckmax(ans, best+1);
        insert(idx+1,best+1);
    }
    cout<<ans<<endl;
}
