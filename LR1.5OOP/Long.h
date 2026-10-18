#pragma once
#include <string>
#include "Pair.h"

class Long {
private:
    static const int BASE = 1000; // База розряду для молодшої частини (0..999)
    Pair pair; // Композиція: Long містить об'єкт Pair

    // Допоміжні методи для зручної математики
    long long toValue() const;
    void fromValue(long long val);

public:
    Pair getPair() const { return pair; }
    int getHigh() const { return pair.getFirst(); }
    int getLow() const { return pair.getSecond(); }

    // Методи запису з обов'язковою перевіркою коректності молодшої частини
    bool setPair(Pair p);
    bool setHigh(int high);
    bool setLow(int low);

    bool Init(int high, int low);
    bool Init(Pair p);
    void Read();
    void Display() const;
    std::string toString() const;

    // Специфічні операції варіанта 18
    Long add(const Long& other) const; // Перевизначене додавання з переносом розряду
    Long sub(const Long& other) const; // Віднімання
    Long mul(const Long& other) const; // Множення
};