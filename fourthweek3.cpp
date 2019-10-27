#include <iostream>
using namespace std;

class Array2 {
    private:
        int *p;
        int row, col;
    public:
        Array2 ();
        Array2 (int, int);
        Array2 (const Array2 &);
        ~Array2 ();
        Array2 & operator = (const Array2 &);
        int * operator [] (int);
        int & operator () (int, int);
};

Array2::Array2 (): p(NULL), row(0), col(0) {}

Array2::Array2 (int a, int b): row(a), col(b) {
    p = new int[a * b];
    memset(p, 0, a * b);
}

Array2::Array2 (const Array2 & a): row(a.row), col(a.col) {
    if (!a.p) {
        p = NULL;
        return;
    }

    p = new int[row * col];
    memcpy(p, a.p, sizeof(int) * row * col);
    memset(p, 0, row * col);
}

Array2::~Array2 () {
    if (p) delete [] p;
}

Array2 & Array2::operator = (const Array2 & a) {
    if (a.p == p) return *this;

    if (p) delete [] p;

    if (!a.p) {
        p = NULL;
        row = col = 0;
        return *this;
    }

    row = a.row;
    col = a.col;
    p = new int[row * col];
    memcpy(p, a.p, sizeof(int) * row * col);
    return *this;
}

int * Array2::operator [] (int n) {
    return p + n * col;
}

int & Array2::operator () (int a, int b) {
    return p[a * col + b];
}

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;   b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
