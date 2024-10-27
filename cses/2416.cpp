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
 
vector<ll>v;
ll pref[maxn], nextBig[maxn], suf[maxn];
pair<ll,int>table[maxn][22];//best,idx of best
 
int main(){_
    int n,q;cin>>n>>q;
    v.resize(n+1);
    for(int i=1;i<=n;++i){
        cin>>v[i];    
        pref[i] = pref[i-1] + v[i];
    }
    
    stack<pair<ll,int>>st;
    st.push({ll(1e9+1),n+1});
 
    for(int i=n;i>=1;--i){
        while(st.top().first<=v[i])st.pop();
        nextBig[i] = st.top().second;//nextbig[i] = first j>i such that v[i] < v[j]
        st.push({v[i],i});
    }
 
    for(int j=0;j<=20;++j){
        for(int i=1;i+(1<<j)<=n+1;++i){
            if(j==0)table[i][j] = {v[i],i};
            else{
                table[i][j].first = max(table[i][j-1].first,table[i+(1<<(j-1))][j-1].first);
                if(table[i][j-1].first==table[i][j].first)table[i][j].second = table[i][j-1].second;
                else table[i][j].second = table[i+(1<<(j-1))][j-1].second;
            } 
        }
    }   
 
    for(ll i=n;i>=1;--i)
        suf[i] = v[i]*(nextBig[i]-i-1ll)-(pref[nextBig[i]-1]-pref[i])+suf[nextBig[i]];
 
    auto query = [&](int l,int r){
        int best = table[l][0].first, idx = l, current = l;
        for(int i=20;~i;--i)
            if(current+(1<<i)-1<=r){
                if(ckmax(best,table[current][i].first))idx = table[current][i].second;
                current+=(1<<i);
            }
        return idx;
    };
    for(int i=1;i<=q;++i){
        int l,r;cin>>l>>r;
        int best = query(l,r), nxt = nextBig[best];
        ll answer = suf[l] - suf[nxt] - ((nxt-r-1)*v[best] - (pref[nxt-1]-pref[r]));
        cout<<answer<<endl;
    }
 
}
