#include <iostream>
#include <vector>

using ull = unsigned long long;

using namespace std;

ull exp_sum(unsigned int n) {
  vector<vector<ull>> combinations_;
  vector<ull> store_combinations_;
  
  int cnt=0;

  for(int i=n; i>0;i--){
    for(int j=n;j>0;j-=i){
      if(j>=i){
        store_combinations_.push_back(i);
      }
      else{
        store_combinations_.push_back(j);
      }
    }
    combinations_.push_back(store_combinations_);
    store_combinations_.clear();
  }
  
  int sum=0;
  for(vector<ull> c: combinations_){
    sum+=c.size();
    for(ull d: c){
      cout<<d<<" ";
    }
    cout<<endl;
  }
  return sum;
}

int main(){
    // for(int x=0; x<=10;x++){
    //   cout<< x<<": "<<exp_sum(x)<<endl;
    // }
    exp_sum(10);
    return 0;
}