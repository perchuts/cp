#include <bits/stdc++.h>
#define maxn (int)(8*(1e5+10))
#define ll long long
using namespace std;
int n,q;
ll seg[maxn];
pair<ll,int>lazy[maxn];
 
void build(int i,int l,int r,int x,int d){
    if(l>x||r<x)return;
    if(r==l&&l==x){
        seg[i]=d;
        return;
    }
    int md=(l+r)/2;
    build(2*i,l,md,x,d);
    build(2*i+1,md+1,r,x,d);
    seg[i]=seg[2*i]+seg[2*i+1];
}
 
void push(int i,int l,int r){
    if(lazy[i].first){
        if(lazy[i].second==2){
            seg[i]=(r-l+1)*lazy[i].first;
            if(l!=r){
                lazy[2*i]=lazy[i];
                lazy[2*i+1]=lazy[i];
            }
        }else{
            seg[i]+=(r-l+1)*lazy[i].first;
            if(l!=r){
                lazy[2*i].first+=lazy[i].first;
                lazy[2*i+1].first+=lazy[i].first;
            }
        }
        lazy[i]={0,0};
    }
}
 
 
void update(int i,int l,int r,int x,int y,int d,int t){
    push(i,l,r);
    if(l>y||r<x)return;
    if(l>=x&&r<=y){
        lazy[i]={d,t};
        push(i,l,r);
        return;
    }
    int md=(l+r)/2;
    update(2*i,l,md,x,y,d,t);
    update(2*i+1,md+1,r,x,y,d,t);
    seg[i]=seg[2*i]+seg[2*i+1];
}
 
ll query(int i,int l,int r,int x,int y){
    push(i,l,r);
    if(l>y||r<x)return 0;
    if(l>=x&&r<=y)return seg[i];
    int md=(l+r)/2;
    return query(2*i,l,md,x,y)+query(2*i+1,md+1,r,x,y);
}
 
int main(int argc, char const *argv[])
{
    cin>>n>>q;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        build(1,0,n-1,i,a);
    }
    while(q--){
        int o,l,r;
        cin>>o>>l>>r;
        if(o==3){
            cout<<query(1,0,n-1,l-1,r-1)<<"\n";
        }else{
            int d;
            cin>>d;
            update(1,0,n-1,l-1,r-1,d,o);
        }
    }
    return 0;
}
