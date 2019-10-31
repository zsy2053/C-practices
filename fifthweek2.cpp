#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class MyString
{
// 在此处补充你的代码
	private:
		char* s;
	public:
		MyString(const char* src){
			s=new char[strlen(src)+1];
			strcpy(s,src);
		}
		MyString(){
			s=new char[1];
			s[0]='\0';
		}
		MyString(const MyString &S){
			s=new char[strlen(S.s)+1];
			strcpy(s,S.s);
		}
		~MyString(){
			delete [] s;
		}
		MyString& operator=(const MyString& S){
			if(s==S.s) return *this;
			if(strlen(s)<strlen(S.s)){
				delete [] s;
				s=new char[strlen(S.s)+1];
			}
			strcpy(s,S.s);
			return *this;
		}
		friend MyString operator+(const MyString& S1, const MyString& S2){
			char* p;
			p=new char[strlen(S1.s)+strlen(S2.s)+1];
			strcpy(p,S1.s);
			strcat(p,S2.s);
			return MyString(p);
		}
		void operator+=(const MyString& S){
			*this=*this+S;
		}
		bool operator<(const MyString& S){
			if(strcmp(s,S.s)==-1) return true;
			else return false;
		}
		bool operator>(const MyString& S){
			if(strcmp(s,S.s)==1) return true;
			else return false;
		}
		bool operator==(const MyString& S){
			if(strcmp(s,S.s)==0) return true;
			else return false;
		}
		char& operator[](int i){
			return s[i];
		}
		char* operator()(int start,int l){
			char* c=new char[l+1];
			for(int i=0;i<l;++i) c[i]=s[start+i];
			c[l]='\0';
			return c;
		}
		friend ostream& operator<<(ostream& o, const MyString &S){
			return o<<S.s;
		}
};

int CompareString( const void * e1, const void * e2) {
    MyString * s1 = (MyString * ) e1;
    MyString * s2 = (MyString * ) e2;
    if( *s1 < *s2 )     return -1;
    else if( *s1 == *s2 ) return 0;
    else if( *s1 > *s2 ) return 1;
}
int main() {
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3;    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;    s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray,4,sizeof(MyString), CompareString);
    for( int i = 0;i < 4;++i )
        cout << SArray[i] << endl;
    //输出s1从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //输出s1从下标为5开始长度为10的子串
    cout << s1(5,10) << endl;
    return 0;
}
