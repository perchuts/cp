#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
  int N,nambe[1000500];
  cin>>N;
  if(N<4&&N>1)cout<<"NO SOLUTION";
  else if(N==1)cout<<"1";
  else if(N==4)cout<<"2 4 1 3";
  else{
    if(N%2){
    for(int i=0;i<N/2;i+=2){
      if(i%2){
        nambe[i] = i+1;
        nambe[i+1] = N-i-2;
        nambe[N-i-1] = N-i-2;
        nambe[N-i-2] = N-i-2;
      }else{
        nambe[i] = N-i-1;
        nambe[i+1] = i+2;
        nambe[N-i-1] = i+1;
        nambe[N-i-2] = N-i-2;
      }
    }
    nambe[(N/2)] = N;
  }
  else{
    for(int i=0;i<(N-1)/2;i+=2){
      if(i%2){
        nambe[i] = i+1;
        nambe[i+1] = N-i-3;
        nambe[N-i-2] = N-i-2;
        nambe[N-i-3] = i+2;
      }else{
        nambe[i] = N-i-2;
        nambe[i+1] = i+2;
        nambe[N-i-3] = N-i-3;
        nambe[N-i-2] = i+1;
      }
    }
    nambe[((N-1)/2)] = N-1;
    nambe[N-1] = N;
  }
  for(int i=0;i<N;i++)cout<<nambe[i]<<" ";
  }
    return 0;
  }
