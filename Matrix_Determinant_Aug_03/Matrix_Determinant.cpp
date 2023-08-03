#include <iostream>
#include <vector>

using namespace std;

long long determinant(vector< vector<long long> > m) {
  // TODO: Return the determinant of the square matrix passed in
  
  //Checks if m is empty
  if(m.empty()){
    return 0;
  }
  //return Value In m If Size == 1
  if(m.size()==1){
    return m[0][0];  
  }
  //Base Case
  //a*d - b*c
  else if(m.size()==2){
    int a,b,c,d = 0;
    
    a = m[0][0];
    b = m[0][1];
    c = m[1][0];
    d = m[1][1];
    return a*d - b*c;
  }
  //Recursive Fuction Of determinant
  //a*determinant(a) - b*determinant(b) + c*determinant(c) - d*determinant(d)...
  else{
    //Temporary Vectors To Store Determinants Of Each Element In m[0] Row
    vector< vector<long long> > temp_2d_vect;
    vector<long long> inner_vect;

    int det_ans=0;

    // y Loop Iterates Through Top Row Of m Vector
    for(int y =0; y<m.size(); y++){
      //x Loop Iterates Through m 2d Vector Except 1st Row
      for(int x=1; x<m.size(); x++){
        //z Loop Iterates Through All Columns In m 2s Vector
        for(int z=0; z<m.size(); z++){
          // Adds The Element To inner_vect If The Element Is NOT In The Same Column As The y Value
          if(z != y){
            inner_vect.push_back(m[x][z]);
          }
        }
        temp_2d_vect.push_back(inner_vect);
        inner_vect.clear();
      }
      //Checks If m Column Index Is Even Or Odd
      if(y%2 == 0){
        det_ans+=m[0][y]*(determinant(temp_2d_vect));
      }
      else{
        det_ans-=m[0][y]*(determinant(temp_2d_vect));
      }
      temp_2d_vect.clear();
    }
    
    return det_ans;
  }
  return 0;
}

int main(){
  // 1st 3 Test Are From Code_Wars
  // 4th Test Was Made Up To Make Sure Code Worked With Higher m Dimension
  int test_1_ans = 1;
  vector< vector<long long> > test_1= vector< vector<long long> > {
      vector<long long> {1}
    };
  
  int test_2_ans = -1;
  vector< vector<long long> > test_2= vector< vector<long long> > {
      vector<long long> {1, 3},
      vector<long long> {2, 5}
    };

  int test_3_ans = -20;
  vector< vector<long long> > test_3= vector< vector<long long> > {
      vector<long long> {2, 5, 3},
      vector<long long> {1, -2, -1},
      vector<long long> {1, 3, 4}
    };
  int test_4_ans = 60;
  vector< vector<long long> > test_4= vector< vector<long long> > {
      vector<long long> {2, 5, 3,1},
      vector<long long> {1, -2, -1,2},
      vector<long long> {1, 3, 4,6},
      vector<long long> {2, 5, 3,-2}
  };
  cout<<"Test 1: "<<"Output=  "<<determinant(test_1)<< "  Actual=  "<<test_1_ans <<endl;
  cout<<"Test 2: "<<"Output=  "<<determinant(test_2)<< "  Actual=  "<<test_2_ans <<endl;
  cout<<"Test 3: "<<"Output=  "<<determinant(test_3)<< "  Actual=  "<<test_3_ans <<endl;
  cout<<"Test 4: "<<"Output=  "<<determinant(test_4)<< "  Actual=  "<<test_4_ans <<endl;

  return 0;
}