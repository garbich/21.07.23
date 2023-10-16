#include <iostream>

using namespace std;

class Fraction {
private:
    int wholePart;
    int fractionalPart;

public:
    Fraction(int whole, int fractional) : wholePart(whole), fractionalPart(fractional) {}

    void print() const {
        cout << wholePart << '.' << fractionalPart << endl;
    }

    Fraction operator+(const Fraction& other) const {
        int newWhole = wholePart + other.wholePart;
        int newFraction = fractionalPart + other.fractionalPart;
        if (newFraction >= 100) {
            newFraction -= 100;
            newWhole++;
        }
        return Fraction(newWhole, newFraction);
    }

    Fraction operator-(const Fraction& other) const {
        int newWhole = wholePart - other.wholePart;
        int newFraction = fractionalPart - other.fractionalPart;
        if (newFraction < 0) {
            newFraction += 100;
            newWhole--;
        }
        return Fraction(newWhole, newFraction);
    }

    Fraction operator*(const Fraction& other) const {
        int newWhole = wholePart * other.wholePart;
        int newFraction = (fractionalPart * other.wholePart) + (wholePart * other.fractionalPart) + (fractionalPart * other.fractionalPart / 100);
        newWhole += newFraction / 100;
        newFraction %= 100;
        return Fraction(newWhole, newFraction);
    }

    bool operator<(const Fraction& other) const {
        return (wholePart < other.wholePart) || (wholePart == other.wholePart && fractionalPart < other.fractionalPart);
    }
};

int main() {
    Fraction a(3, 50);
    Fraction b(1, 75);

    Fraction sum = a + b;
    Fraction difference = a - b;
    Fraction product = a * b;

    cout << "a + b = ";
    sum.print();
    cout << "a - b = ";
    difference.print();
    cout << "a * b = ";
    product.print();

    if (a < b) {
        cout << "a < b" << endl;
    }
    else {
        cout << "a >= b" << endl;
    }

    return 0;
}
