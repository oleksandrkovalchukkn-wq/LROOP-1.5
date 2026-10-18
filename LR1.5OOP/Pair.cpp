#include "Pair.h"
#include <iostream>
#include <sstream>

using namespace std;

bool Pair::setFirst(int value) {
    first = value;
    return true;
}

bool Pair::setSecond(int value) {
    second = value;
    return true;
}

bool Pair::Init(int a, int b) {
    return setFirst(a) && setSecond(b);
}

void Pair::Read() {
    int a, b;
    do {
        cout << "  Введіть перше число (first): ";
        cin >> a;
        cout << "  Введіть друге число (second): ";
        cin >> b;
    } while (!Init(a, b));
}

string Pair::toString() const {
    stringstream sout;
    sout << "(" << first << ", " << second << ")";
    return sout.str();
}

void Pair::Display() const {
    cout << toString() << endl;
}

Pair Pair::add(const Pair& other) const {
    Pair result;
    result.Init(this->first + other.first, this->second + other.second);
    return result;
}