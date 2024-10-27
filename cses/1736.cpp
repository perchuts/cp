#include <bits/stdc++.h>
#define maxn (int)(8*1e5+10)
#define ll long long int
using namespace std;
int n,q;
ll seg[maxn], p[200500];
pair<ll,ll>lazy[maxn];
 
void push(ll i,ll l,ll r){
    if(lazy[i].first!=0){
        seg[i]+=lazy[i].first;
        if(l!=r){
            ll qtd=r-l+1;
            ll md=(l+r)/2;
            ll temp=((lazy[i].first-(lazy[i].second*(((1+qtd)*(qtd))/2)))/qtd)*(md+1-l)+lazy[i].second*(((1+(md+1-l))*(md+1-l))/2);
            lazy[2*i].first+=temp;
            lazy[2*i+1].first+=lazy[i].first-temp;
            lazy[2*i].second+=lazy[i].second;
            lazy[2*i+1].second+=lazy[i].second;
        }
        lazy[i]={0,0};
    }
}
 
void update(ll i,ll l,ll r,ll x,ll y){
    push(i,l,r);
    if(l>y||r<x)return;
    if(l>=x&&r<=y){
        lazy[i].first=((2*(l-x+1)+r-l)*(r-l+1))/2;
        lazy[i].second=1;
        push(i,l,r);
        return;
    }
    int md=(l+r)/2;
    update(2*i,l,md,x,y);
    update(2*i+1,md+1,r,x,y);
    seg[i]=seg[2*i]+seg[2*i+1];
}
 
ll query(int i, int l, int r, int x, int y)
{
    push(i, l, r);
    if (l > y || r < x)
        return 0;
    if (l >= x && r <= y)
        return seg[i];
    int md = (l + r) / 2;
    return query(2 * i, l, md, x, y) + query(2 * i + 1, md + 1, r, x, y);
}
 
int main(int argc, char const *argv[])
{   
    cin>>n>>q;
    ll a;
    for(int i=0;i<n;i++){
        cin>>a;
        p[i+1]=p[i]+a;
    }
    while(q--){
        int a,b,o;
        cin>>o>>a>>b;
        if(o==1){
            update(1,0,n-1,a-1,b-1);
        }else{
            cout<<query(1,0,n-1,a-1,b-1)+(p[b]-p[a-1])<<endl;
        }
    }
    return 0;
}
