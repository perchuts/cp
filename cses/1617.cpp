#include <bits/stdc++.h>
 
using namespace std;
 
long long int power(long long int a,long long int b){
  if(!b)return 1;
  int c=a;
  for(long long int i=1;i<b;i++){
    a*=c;
  }
  return a;
}
 
int main(int argc, char const *argv[]) {
  int N;
  cin>>N;
  long long int ans = 1;
  while(1){
    if(N<=31){
      ans = (ans*power(2,N))%(1000000007);
      break;
    }
    N-=31;
    ans = ((ans*power(2,31))%(1000000007));
  }
 
  cout<<ans;
  return 0;
}
