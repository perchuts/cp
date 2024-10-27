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
 
pair<ii,int> v[maxn];
ii ans[maxn];
int main(){_
    int n;cin>>n;
    for(int i=1;i<=n;++i)cin>>v[i].first.first>>v[i].first.second, v[i].second = i;
    sort(v+1,v+1+n, [&](pair<ii,int> x,pair<ii,int> y){
        if(x.first.first==y.first.first)return x.first.second>y.first.second;
        return x.first.first<y.first.first;
    });
    stack<pair<ii,int>>st;
    for(int i=1;i<=n;++i){
        while(!st.empty()&&st.top().first.second<v[i].first.second)st.pop();
        if(sz(st))ans[v[i].second].second = 1;
        st.push(v[i]);
    }
    reverse(v+1,v+1+n);
    while(!st.empty())st.pop();
    for(int i=1;i<=n;++i){
        while(!st.empty()&&st.top().first.second>v[i].first.second)st.pop();
        if(sz(st))ans[v[i].second].first = 1;
        st.push(v[i]);
    }
    for(int i=1;i<=n;++i)cout<<ans[i].first<<" \n"[i==n];
    for(int i=1;i<=n;++i)cout<<ans[i].second<<" \n"[i==n];
}
