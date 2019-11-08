#include <iostream>

#include <map>

using namespace std;

class Gt

{

public:

bool operator() (const int & n1,

const int & n2) const {

return ( n1 % 10 ) > ( n2 % 10);

}

};

int main() {

typedef map <int,double,Gt> mmid;

mmid MyMap;

cout << MyMap.count(15) << endl;

MyMap.insert(mmid::value_type(15,2.7));

MyMap.insert(mmid::value_type(15,99.3));

cout << MyMap.count(15) << endl;

MyMap.insert(mmid::value_type(30,111.11));

MyMap.insert(mmid::value_type(11,22.22));

cout << MyMap[16] << endl;

for( mmid::const_iterator i = MyMap.begin();

i != MyMap.end() ;++i )

cout << "(" << i->first << ","<< i->second << ")" << ",";

return 0;

}
