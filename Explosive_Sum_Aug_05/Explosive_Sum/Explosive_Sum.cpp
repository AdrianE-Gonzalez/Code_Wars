#include <iostream>

using ull = unsigned long long;

using namespace std;

ull exp_sum(unsigned int n) {
  
  //Base Case
  if(n<1){
    return 1;
  }
  //Recursion
  else{
    return exp_sum(n-1)+n;

  }
  
}

int main(){
    for(int x=0; x<=10;x++){
      cout<< x<<": "<<exp_sum(x)<<endl;
    }
    return 0;
}