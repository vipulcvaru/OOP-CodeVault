#include <iostream>
#include <cmath>
using namespace std;

class Complex {
public:
    float real;
    float img;

    Complex() {
        real = 0;
        img = 0;
    }

    Complex(float a, float b) {
        real = a;
        img = b;
    }

    void print() {
        cout << real << "+" << img << "i" << endl;
    }

    Complex operator+(Complex &c) {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }

    Complex operator-(Complex &c) {
        Complex temp;
        temp.real = real - c.real;
        temp.img = img - c.img;
        return temp;
    }

    Complex operator*(Complex &c) {
        Complex t;
        t.real = (real * c.real) - (img * c.img);
        t.img = (real * c.img) + (img * c.real);
        return t;
    }

    Complex operator/(Complex &c) {
        Complex result;
        float denominator = c.real * c.real + c.img * c.img;
        result.real = (real * c.real + img * c.img) / denominator;
        result.img = (img * c.real - real * c.img) / denominator;
        return result;
    }

    Complex conjugate() {
        return Complex(real, -img);
    }

    float magnitude() {
        return sqrt(real * real + img * img);
    }

    float angle() {
        return atan2(img, real);
    }

    friend istream &operator>>(istream &in, Complex &c);
    friend ostream &operator<<(ostream &out, Complex &c);
};

istream &operator>>(istream &in, Complex &c) {
    cout << "Enter real and imaginary part: ";
    in >> c.real >> c.img;
    return in;
}

ostream &operator<<(ostream &out, Complex &c) {
    out << c.real << "+" << c.img << "i";
    return out;
}

int main() {
    Complex c1, c2;
    cout << "Enter the first complex number:" << endl;
    cin >> c1;
    cout << "Enter the second complex number:" << endl;
    cin >> c2;

    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;
    Complex c6 = c1 / c2;

    cout << "Sum of the complex numbers: " << c3 << endl;
    cout << "Difference of the complex numbers: " << c4 << endl;
    cout << "Product of the complex numbers: " << c5 << endl;
    cout << "Division of the complex numbers: " << c6 << endl;

    Complex conj = c1.conjugate();
    float mag = c1.magnitude();
    float ang = c1.angle();

    cout << "Conjugate of the first complex number: " << conj << endl;
    cout << "Magnitude of the first complex number: " << mag << endl;
    cout << "Angle of the first complex number: " << ang << " radians" << endl;

    return 0;
}
