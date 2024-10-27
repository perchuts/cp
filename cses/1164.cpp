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
 
ii v[maxn];
vector<ii>points;
vector<iii>points2;
int resp[maxn];
int main(){_
    int n;cin>>n;
    for(int i=1;i<=n;++i)cin>>v[i].first>>v[i].second, points.pb({v[i].first,1}), points.pb({v[i].second+1,-1});    
    sort(all(points));
    int k = 0, cur = 0;
    for(auto [c,x]:points){
        cur += x, ckmax(k,cur);
    }
    vector<int>available(k);
    iota(all(available),1);
    for(int i=1;i<=n;++i)points2.pb({v[i].first,1,i}), points2.pb({v[i].second+1,-1,i});
    sort(all(points2));
    for(auto [coord,add,idx]:points2){
        if(add==1){
            resp[idx] = available.back();
            available.pop_back();
        }else{
            available.pb(resp[idx]);
        }
    }
    cout<<k<<endl;
    for(int i=1;i<=n;++i)cout<<resp[i]<<" \n"[i==n];
    //sweep line
}
