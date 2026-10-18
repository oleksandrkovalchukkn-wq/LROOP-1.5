#include "Long.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

// Збираємо старшу і молодшу частину в одне ціле число для точних розрахунків
long long Long::toValue() const {
    long long sign = (pair.getFirst() < 0) ? -1 : 1;
    return static_cast<long long>(pair.getFirst()) * BASE + sign * pair.getSecond();
}

// Розкладаємо число назад на старшу і молодшу частини
void Long::fromValue(long long val) {
    int high = static_cast<int>(val / BASE);
    int low = static_cast<int>(std::abs(val % BASE));
    pair.Init(high, low);
}

bool Long::setHigh(int high) {
    return pair.setFirst(high);
}

// Перевірка на коректність: молодша частина має бути строго в межах [0..999]
bool Long::setLow(int low) {
    if (low >= 0 && low < BASE) {
        return pair.setSecond(low);
    }
    return false;
}

bool Long::setPair(Pair p) {
    return Init(p.getFirst(), p.getSecond());
}

bool Long::Init(int high, int low) {
    return setHigh(high) && setLow(low);
}

bool Long::Init(Pair p) {
    return Init(p.getFirst(), p.getSecond());
}

void Long::Read() {
    int h, l;
    do {
        cout << "  Введіть старшу частину (тисячі): ";
        cin >> h;
        cout << "  Введіть молодшу частину (від 0 до 999): ";
        cin >> l;
        if (l < 0 || l >= BASE) {
            cout << "  [Помилка!] Молодша частина має бути від 0 до 999. Спробуйте ще раз.\n";
        }
    } while (!Init(h, l));
}

string Long::toString() const {
    stringstream sout;
    sout << toValue() << " [Старша: " << pair.getFirst()
        << ", Молодша: " << setw(3) << setfill('0') << pair.getSecond() << "]";
    return sout.str();
}

void Long::Display() const {
    cout << toString() << endl;
}

// Перевизначене додавання: делегуємо базове додавання класу Pair, 
// після чого виконуємо корекцію переносу розряду
Long Long::add(const Long& other) const {
    Long result;
    if (this->getHigh() >= 0 && other.getHigh() >= 0) {
        Pair rawSum = this->pair.add(other.pair); // Делегування методу класу Pair
        int carry = rawSum.getSecond() / BASE;    // Рахуємо перенос у старший розряд
        int newHigh = rawSum.getFirst() + carry;
        int newLow = rawSum.getSecond() % BASE;
        result.Init(newHigh, newLow);
    }
    else {
        result.fromValue(this->toValue() + other.toValue());
    }
    return result;
}

// Віднімання
Long Long::sub(const Long& other) const {
    Long result;
    result.fromValue(this->toValue() - other.toValue());
    return result;
}

// Множення
Long Long::mul(const Long& other) const {
    Long result;
    result.fromValue(this->toValue() * other.toValue());
    return result;
}