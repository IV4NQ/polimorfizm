#include <iostream>
#include <cmath>

using namespace std;

class Wielokat {
public:
    virtual double obw() = 0;
};

class Okrag : public Wielokat {
    double r;
public:
    Okrag(double r) { this->r = r; }

    double obw() override {
        return 2 * M_PI * r;
    }
};

class Kwadrat : public Wielokat {
    double a;
public:
    Kwadrat(double a) { this->a = a; }

    double obw() override {
        return 4 * a;
    }
};

class Trojkat : public Wielokat {
    double a, b, c;
public:
    Trojkat(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    double obw() override {
        return a + b + c;
    }
};

class Prostokat : public Wielokat {
    double a, b;
public:
    Prostokat(double a, double b) {
        this->a = a;
        this->b = b;
    }

    double obw() override {
        return a + a + b + b;
    }
};

int main() {
    Kwadrat k1(4);
    Prostokat p1(2, 7);
    Okrag o1(2);
    Trojkat t1(2, 6, 9);

    Wielokat *wsk;

    wsk = &k1;
    cout << "\nObwod kwadratu: " << wsk->obw();

    wsk = &p1;
    cout << "\nObwod prostokata: " << wsk->obw();

    wsk = &o1;
    cout << "\nObwod okregu: " << wsk->obw();

    wsk = &t1;
    cout << "\nObwod trojkata: " << wsk->obw();
    return 0;
}