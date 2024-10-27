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
const int maxn = 1001;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
map<int,int>cnt;
vector<ii>v;
map<int,vector<ii>>mp;
int main(){_
    int n,target;cin>>n>>target;
    v.pb({0,0});
    for(int i=1;i<=n;++i){
        int x;cin>>x;
        cnt[x]++;
        if(cnt[x]>5)continue;
        else v.pb({x,i});
    }
    n = sz(v) - 1;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(v[i].first+v[j].first<target){
                int a = v[i].second, b = v[j].second;
                for(auto [x,y]:mp[target-v[i].first-v[j].first]){
                    if(x==a||x==b||y==a||y==b)continue;
                    cout<<a<<" "<<b<<" "<<x<<" "<<y<<endl;
                    return 0;
                }
            }
            mp[v[i].first+v[j].first].pb({v[i].second,v[j].second});
        }
    }
 
 
    cout<<"IMPOSSIBLE"<<endl;
}   
