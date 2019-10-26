  // #include <iostream>
  // using namespace std;
  // class CSample {
  //
  // int x;
  //
  // public:
  //
  // CSample() { cout << "C1" << endl; }
  //
  // CSample(int n ) {
  //
  // x = n;
  //
  // cout << "C2,x=" << n << endl; }
  //
  // };
  //
  // int main(){
  //
  // CSample array1[2];
  //
  // CSample array2[2] = {6,8};
  //
  // CSample array3[2] = {12};
  //
  // CSample * array4 = new CSample[3];
  //
  // return 0;
  //
  // }
#include <iostream>

using namespace std;

class Sample{

public:

int v;

Sample() { };

Sample(int n):v(n) { };

Sample(const Sample & x) { v = 2 + x.v ; }

};

Sample PrintAndDouble( Sample o) {

cout << o.v;

o.v = 2 * o.v;

return o;

}

int main() {

Sample a(5);

Sample b = a;

Sample c = PrintAndDouble( b );

cout << endl;

cout << c.v << endl;

Sample d;

d = a;

cout << d.v ;

}
