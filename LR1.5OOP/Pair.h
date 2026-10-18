#pragma once
#include <string>

class Pair {
private:
    int first;
    int second;

public:
    int getFirst() const { return first; }
    int getSecond() const { return second; }

    bool setFirst(int value);
    bool setSecond(int value);

    bool Init(int a, int b);
    void Read();
    void Display() const;
    std::string toString() const;

    // Операція додавання пар: (a, b) + (c, d) = (a + c, b + d)
    Pair add(const Pair& other) const;
};