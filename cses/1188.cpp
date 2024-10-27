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
 
//segment tree
 
bool type[maxn];
 
struct node{
    int prlen, suflen, prtype, suftype, best, tot;
}seg[4*maxn];
 
void upd(int i){
    node l = seg[2*i], r = seg[2*i+1];
    seg[i].prtype = l.prtype, seg[i].suftype = r.suftype;
 
    if(l.best==l.tot&&l.prtype==r.prtype)seg[i].prlen = l.tot+r.prlen;
    else seg[i].prlen = l.prlen;
 
    if(r.best==r.tot&&r.suftype==l.suftype)seg[i].suflen = r.tot+l.suflen;
    else seg[i].suflen = r.suflen;
 
    seg[i].best = max({l.best,r.best,(l.suftype==r.prtype?l.suflen+r.prlen:0)}), seg[i].tot = l.tot+r.tot;
 
}
//000011
//010011
//010001
 
void build(int i,int l,int r){
    if(l==r){
        seg[i].prlen = seg[i].suflen = seg[i].best = seg[i].tot = 1, seg[i].prtype = seg[i].suftype = type[l];
        return;
    }
    int md = (l+r)/2;
    build(2*i,l,md);build(2*i+1,md+1,r);
    upd(i);
}
 
void update(int i,int l,int r,int x){
    if(l>x||r<x)return;
    if(l==r){
        type[l]^=1, seg[i].prtype = seg[i].suftype = type[l];
        return;
    }   
    int md = (l+r)/2;
    update(2*i,l,md,x);update(2*i+1,md+1,r,x);
    upd(i);
}
 
int main(){_
    string s;cin>>s;
    int n = sz(s);
    for(int i=1;i<=n;++i)type[i] = s[i-1]=='1';
    build(1,1,n);
    int m;cin>>m;
    for(int i=1;i<=m;++i){
        int x;cin>>x;
        update(1,1,n,x);
        cout<<seg[1].best<<" \n"[i==m];
    }
}
