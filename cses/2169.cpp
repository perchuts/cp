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
 
pair<ii,int>v[maxn];
 
int bit[maxn],n;
vector<int>cmp;
void insert(int x){
    for(;x<=n;x+=x&(-x))bit[x]++;
}
 
int query(int x){
    int ans = 0;
    while(x){
        ans += bit[x];
        x -= x&(-x);
    }
    return ans;
}
 
ii ans[maxn];
 
int main(){_
    cin>>n;
    for(int i=1;i<=n;++i)cin>>v[i].first.first>>v[i].first.second,cmp.pb(v[i].first.second), v[i].second = i;
    sort(all(cmp));
    for(int i=1;i<=n;++i)v[i].first.second = lower_bound(all(cmp),v[i].first.second) - begin(cmp) + 1;
    sort(v+1,v+1+n, [&](pair<ii,int> x,pair<ii,int> y){
        if(x.first.first==y.first.first)return x.first.second>y.first.second;
        return x.first.first<y.first.first;
    });
    for(int i=n;i>=1;--i){
        ans[v[i].second].first += query(v[i].first.second);
        insert(v[i].first.second);
    }
    for(int i=1;i<=n;++i)bit[i] = 0;
    for(int i=1;i<=n;++i){
        ans[v[i].second].second += i-1 - query(v[i].first.second-1); 
        insert(v[i].first.second);
    }
    for(int i=1;i<=n;++i)cout<<ans[i].first<<" \n"[i==n];
    for(int i=1;i<=n;++i)cout<<ans[i].second<<" \n"[i==n];
}
