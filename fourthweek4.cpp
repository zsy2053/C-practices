#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int N = 200;

class BigInt {
    private:
        int bigint[N];
        int length;
        bool sign;

    public:
        BigInt ();
        BigInt (const char *);
        BigInt (const BigInt &);

        friend ostream & operator << (ostream &, const BigInt &);
        int & operator [] (int i);

        BigInt operator + (const BigInt &);
        BigInt operator - (const BigInt &);
        BigInt operator * (const BigInt &);
        BigInt operator / (const BigInt &);
        BigInt & operator = (const BigInt &);

        bool operator > (const BigInt &);
        bool operator == (const BigInt &);
        bool operator < (const BigInt &);
        bool operator >= (const BigInt &);
        bool operator <= (const BigInt &);
        bool operator != (const BigInt &);
};

BigInt::BigInt () {
    memset(bigint, 0, sizeof(int) * N);
    length = 0;
    sign = false;
}

BigInt::BigInt (const char *str) {
    sign = false;
    length = strlen(str);
    memset(bigint, 0, sizeof(int) * N);
    for (int i = 0; i < length; i++) {
        bigint[i] = str[length - i - 1] - '0';
    }
    while (length && bigint[length - 1] == 0) {
        length--;
    }
}

BigInt::BigInt (const BigInt & bi) {
    length = bi.length;
    sign = bi.sign;
    memcpy(bigint, bi.bigint, sizeof(int) * N);
}

ostream & operator << (ostream & os, const BigInt & bi) {
    int len = bi.length;
    while (len && bi.bigint[len - 1] == 0) {
        len--;
    }
    if (bi.sign && len) {
        os << "-";
    }
    if (!len) {
        os << "0";
    }
    for (int i = 0; i < len; i++) {
        os << bi.bigint[len - i - 1];
    }
    return os;
}

int & BigInt::operator [] (int i) {
    return bigint[i];
}

BigInt & BigInt::operator = (const BigInt & bi) {
    sign = bi.sign;
    length = bi.length;
    memcpy(bigint, bi.bigint, sizeof(int) * N);
    return *this;
}

BigInt BigInt::operator + (const BigInt & bi) {
    BigInt b;
    int i = 0;
    b.length = length > bi.length ? length : bi.length;
    for (; i < b.length + 1; i++) {
        b.bigint[i] += bigint[i] + bi.bigint[i];
        b.bigint[i + 1] += b.bigint[i] / 10;
        b.bigint[i] = b.bigint[i] % 10;
    }
    if (b.bigint[b.length] > 0) b.length++;
    return b;
}

BigInt BigInt::operator - (const BigInt & bi) {
    BigInt b, max(*this), min(bi);
    if (max == min) {
        return b;
    }
    if (max < min) {
        BigInt tmp = max;
        max = min;
        min = tmp;
        b.sign = true;
    }
    b.length = max.length;
    for (int i = 0; i < max.length; i++) {
        if (max.bigint[i] < min.bigint[i]) {
            max.bigint[i] += 10;
            max.bigint[i + 1] -= 1;
        }
        b.bigint[i] = max.bigint[i] - min.bigint[i];
    }
    while (b.length && b.bigint[b.length - 1] == 0) {
        b.length--;
    }
    return b;
}

BigInt BigInt::operator * (const BigInt & bi) {
    BigInt b;
    if (bi.length == 0 || length == 0) return b;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < bi.length; j++) {
            b.bigint[i + j] += bigint[i] * bi.bigint[j];
            if (b.bigint[i + j] > 9) {
                b.bigint[i + j + 1] += b.bigint[i + j] / 10;
            }
            b.bigint[i + j] = b.bigint[i + j] % 10;
        }
    }
    b.length = length + bi.length;
    while (b.length && b.bigint[b.length - 1] == 0) {
        b.length--;
    }
    return b;
}

BigInt BigInt::operator / (const BigInt & bi) {
    BigInt b;
    if (*this < bi) return b;
    if (*this == bi) return b = "1";

    BigInt dividend(*this), divisor(bi), quotient, tmp, one("1"), zero, ten("10");
    int dividendLength = dividend.length, divisorLength = divisor.length;

    int n = divisorLength - 1;
    while (n >= 0) {
        tmp.bigint[n--] = dividend.bigint[--dividendLength];
    }
    tmp.length = divisorLength;

    while (dividendLength > 0) {
        while (tmp < divisor && dividendLength > 0) {
            int tmplen = ++tmp.length;
            while (tmplen) {
                tmp.bigint[tmplen] = tmp.bigint[tmplen - 1];
                tmplen--;
            }
            tmp.bigint[0] = dividend.bigint[--dividendLength];
            b = b * ten;
        }

        while (quotient * divisor <= tmp) {
            quotient = quotient + one;
        }
        quotient = quotient - one;
        tmp = tmp - quotient * divisor;
        b = b + quotient;
        quotient = zero;
    }

    return b;
}

bool BigInt::operator > (const BigInt & bi) {
    if (length > bi.length) return true;
    if (length < bi.length) return false;
    for (int i = length - 1; i > -1; i--) {
        if (bigint[i] > bi.bigint[i]) {
            return true;
        } else if (bigint[i] < bi.bigint[i]) {
            return false;
        }
    }
    return false;
}

// 比较相等
bool BigInt::operator == (const BigInt & bi) {
    if (length == bi.length) {
        for (int i = 0; i < length; i++) {
            if (bigint[i] != bi.bigint[i]) return false;
        }
        return true;
    }
    return false;
}

bool BigInt::operator < (const BigInt & bi) {
    BigInt b(*this);
    if (b > bi || b == bi) return false;
    return true;
}

bool BigInt::operator >= (const BigInt & bi) {
    BigInt b(*this);
    return b > bi || b == bi || false;
}

bool BigInt::operator <= (const BigInt & bi) {
    BigInt b(*this);
    return b < bi || b == bi || false;
}

bool BigInt::operator != (const BigInt & bi) {
    return !(*this == bi);
}

int main () {
    char a[101], b[101], c;
    cin >> a >> c >> b;
    BigInt b1(a), b2(b);
    switch (c) {
        case '+': cout << (b1 + b2); break;
        case '-': cout << (b1 - b2); break;
        case '*': cout << (b1 * b2); break;
        case '/': cout << (b1 / b2); break;
    }
    return 0;
}
