#include <iostream>
#include <vector>

using namespace std;

class BigInt {
    private:
        vector<int> digits;
    
    public:
        friend bool operator==(const BigInt&, BigInt);
        friend bool operator!=(const BigInt&, BigInt);
        friend bool operator>=(const BigInt&, BigInt);
        friend bool operator<=(const BigInt&, BigInt);
        friend bool operator>(const BigInt&, BigInt);
        friend bool operator<(const BigInt&, BigInt);
        friend istream& operator>>(istream&, BigInt&);
        friend ostream& operator<<(ostream&, BigInt&);
        friend BigInt operator+(const BigInt&, BigInt);
};

bool operator==(const BigInt& a, BigInt b) {
    return a.digits == b.digits;
}

bool operator!=(const BigInt& a, BigInt b) {
    return a.digits != b.digits;
}

bool operator>=(const BigInt& a, BigInt b) {
    return a.digits >= b.digits;
}

bool operator<=(const BigInt& a, BigInt b) {
    return a.digits <= b.digits;
}

bool operator>(const BigInt& a, BigInt b) {
    return a.digits > b.digits;
}

bool operator<(const BigInt& a, BigInt b) {
    return a.digits < b.digits;
}

istream& operator>>(istream& input, BigInt& a) {
    string value;

    input >> value;

    for(char& c : value) a.digits.insert(a.digits.begin(), c - '0');

    return input;
}

ostream& operator<<(ostream& output, BigInt& a) {
    for(int i = a.digits.size() - 1; i >= 0; i--)
        output << a.digits[i];
    
    return output;
}

BigInt operator+(const BigInt& a, BigInt b) {
    BigInt c;
    int value, carry = 0, it;

    if(a.digits.size() > b.digits.size()) it = b.digits.size();
    else it = a.digits.size();

    for(int i = 0; i < it; i++) {
        value = a.digits[i] + b.digits[i] + carry;
        carry = value / 10;
        value %= 10;
        c.digits.push_back(value);
    }

    if(a.digits.size() > b.digits.size()) {
        for(int i = it; i < a.digits.size(); i++) {
            value = a.digits[i] + carry;
            carry = value / 10;
            value %= 10;
            c.digits.push_back(value);
        }
    } else if(a.digits.size() < b.digits.size()) {
        for(int i = it; i < b.digits.size(); i++) {
            value = b.digits[i] + carry;
            carry = value / 10;
            value %= 10;
            c.digits.push_back(value);
        }
    }

    if(carry != 0) c.digits.push_back(carry);

    return c;
}

int main() {
    BigInt a, b, c;

    cin >> a;
    cin >> b;

    cout << a << endl;
    cout << b << endl;

    if(a == b) cout << "A == B" << endl;
    else cout << "A != B" << endl;

    c = a + b;

    cout << "The sum A + B = " << c << endl;

    return 0;
}