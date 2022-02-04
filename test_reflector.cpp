#include "reflector.h"

#include <cassert>

void test_constructors() {
    Reflector r1 = Reflector();
    assert(r1.subs.size() == 0);

    std::vector<sub_t> subs;
    subs.push_back(createSub('A', 'B'));
    subs.push_back(createSub('B', 'C'));
    subs.push_back(createSub('C', 'D'));
    Reflector r2 = Reflector(subs);
    assert(r2.subs.size() == 3);
}

void test_encode() {
    std::vector<sub_t> subs;
    subs.push_back(createSub('A', 'B'));
    subs.push_back(createSub('B', 'C'));
    subs.push_back(createSub('C', 'D'));
    subs.push_back(createSub('D', 'G'));
    Reflector r2 = Reflector(subs);

    assert(r2.encode((uint8_t)0) == 1);
    assert(r2.encode((uint8_t)1) == 2);
    assert(r2.encode((uint8_t)3) == 6);
    assert(r2.encode((uint8_t)5) == 5);
}

int main(int argc, char** argv) {
    test_constructors();
    test_encode();
}