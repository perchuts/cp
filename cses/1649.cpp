#include <bits/stdc++.h>
#define maxn (int)(8*1e5+10)
#define inf (int)(1e9+10);
using namespace std;
int n,q;
int seg[maxn];
 
void update(int i,int l,int r,int x,int y,int d){
    if(l>y||r<x)return;
    if(l>=x&&r<=y){
        seg[i]=d;
        return;
    }
    int md = (l+r)/2;
    update(2*i,l,md,x,y,d);
    update(2*i+1,md+1,r,x,y,d);
    seg[i]=min(seg[2*i],seg[(2*i)+1]);
}
 
int query(int i,int l,int r,int x,int y){
    if(l>y||r<x)return inf;
    if(l>=x&&r<=y){
        return seg[i];
    }
    int md=(l+r)/2;
    return min(query(2*i,l,md,x,y),query(2*i+1,md+1,r,x,y));
}
 
 
 
 
int main(int argc, char const *argv[])
{
    cin>>n>>q;
    for(int i=0;i<(4*n+10);i++)seg[i]=inf;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        update(1,0,n-1,i,i,a);
    }
    while(q--){
        int o,a,b;
        cin>>o>>a>>b;
        if(o==1){
            update(1,0,n-1,a-1,a-1,b);
        }else{
            cout<<query(1,0,n-1,a-1,b-1)<<endl;
        }
    }
    return 0;
}
