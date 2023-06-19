#include "rotor.h"

#include <assert.h>

void test_constructors() {
    Rotor r1 = Rotor();
    assert(r1.notch == 'Z');
    assert(r1.setting == 'A');
    assert(r1.subs.size() == 0);

    std::vector<sub_t> subs;
    subs.push_back(createSub('A', 'B'));
    subs.push_back(createSub('B', 'C'));
    subs.push_back(createSub('C', 'D'));
    Rotor r2 = Rotor(subs, 'A', 'A');
    assert(r2.notch == 'A');
    assert(r2.setting == 'A');
    assert(r2.subs.size() == 3);
}

void test_atPosition() {
    Rotor r1 = Rotor();
    assert(r1.atPosition(0) == 'A');
    assert(r1.atPosition(25) == 'Z');
}

void test_positionOf() {
    std::vector<sub_t> subs;
    subs.push_back(createSub('A', 'B'));
    subs.push_back(createSub('B', 'C'));
    subs.push_back(createSub('C', 'D'));

    Rotor r1 = Rotor(subs, ' ', 'A');
    assert(r1.positionOf('A') == 0);
    assert(r1.positionOf('C') == 2);
    assert(r1.positionOf('E') == 4);    // unspecified substitution

    Rotor r2 = Rotor(subs, ' ', 'Z');
    assert(r2.positionOf('A') == 1);
    assert(r2.positionOf('B') == 2);

    Rotor r3 = Rotor(subs, ' ', 'D');
    assert(r3.positionOf('C') == ('C' - 'D' + 26));
    assert(r3.positionOf('E') == ('E' - 'D'));
    assert(r3.positionOf('D') == ('D' - 'D'));
}

void test_encodeIn() {
    std::vector<sub_t> subs1;
    subs1.push_back(createSub('A', 'B'));
    subs1.push_back(createSub('B', 'C'));
    subs1.push_back(createSub('C', 'D'));

    Rotor r1 = Rotor(subs1, ' ', 'A');
    assert(r1.encodeIn('A') == 'B');
    assert(r1.encodeIn((uint8_t)0) == 1);
    assert(r1.encodeIn('B') == 'C');
    assert(r1.encodeIn((uint8_t)1) == 2);
    assert(r1.encodeIn('C') == 'D');
    assert(r1.encodeIn((uint8_t)2) == 3);

    std::vector<sub_t> subs2;
    subs2.push_back(createSub('A', 'B'));
    subs2.push_back(createSub('B', 'C'));
    subs2.push_back(createSub('C', 'D'));

    Rotor r2 = Rotor(subs2, ' ', 'B');
    // Since the encoding of B is C, A should encode to B
    assert(r2.encodeIn('A') == 'B');
    assert(r2.encodeIn((uint8_t)0) == 1);
    assert(r2.encodeIn('B') == 'C');
    assert(r2.encodeIn((uint8_t)1) == 2);

    assert(r2.encodeIn('C') == 'C'); // this specific instance is invalid, but insightful for testing
    assert(r2.encodeIn((uint8_t)2) == 2);
    assert(r2.encodeIn('Z') == 'A');
    assert(r2.encodeIn((uint8_t)25) == 0);

    std::vector<sub_t> subs3;
    subs3.push_back(createSub('Z', 'B'));
    subs3.push_back(createSub('A', 'C'));
    subs3.push_back(createSub('B', 'D'));
    
    Rotor r3 = Rotor(subs3, ' ', 'Z');
    assert(r3.encodeIn('A') == 'C');
    assert(r3.encodeIn((uint8_t)0) == 2);
    assert(r3.encodeIn('B') == 'D');
    assert(r3.encodeIn((uint8_t)1) == 3);
    assert(r3.encodeIn('C') == 'E');
    assert(r3.encodeIn((uint8_t)2) == 4);
    assert(r3.encodeIn('D') == 'D');
    assert(r3.encodeIn((uint8_t)5) == 5);
}

void test_encodeOut() {
    std::vector<sub_t> subs1;
    subs1.push_back(createSub('A', 'B'));
    subs1.push_back(createSub('B', 'C'));
    subs1.push_back(createSub('C', 'D'));

    Rotor r1 = Rotor(subs1, ' ', 'A');
    assert(r1.encodeOut('B') == 'A');
    assert(r1.encodeOut((uint8_t)1) == 0);
    assert(r1.encodeOut('C') == 'B');
    assert(r1.encodeOut((uint8_t)2) == 1);
    assert(r1.encodeOut('D') == 'C');
    assert(r1.encodeOut((uint8_t)3) == 2);

    std::vector<sub_t> subs2;
    subs2.push_back(createSub('A', 'B'));
    subs2.push_back(createSub('B', 'C'));
    subs2.push_back(createSub('C', 'D'));

    Rotor r2 = Rotor(subs2, ' ', 'B');
    assert(r2.encodeOut('B') == 'A');
    assert(r2.encodeOut((uint8_t)1) == 0);
    assert(r2.encodeOut('C') == 'B');
    assert(r2.encodeOut((uint8_t)2) == 1);
    assert(r2.encodeOut('A') == 'Z');
    assert(r2.encodeOut((uint8_t)0) == 25);
    assert(r2.encodeOut('E') == 'E');
    assert(r2.encodeOut((uint8_t)4) == 4);

    std::vector<sub_t> subs3;
    subs3.push_back(createSub('Z', 'B'));
    subs3.push_back(createSub('A', 'C'));
    subs3.push_back(createSub('B', 'D'));
    
    Rotor r3 = Rotor(subs3, ' ', 'Z');
    assert(r3.encodeOut('C') == 'A');
    assert(r3.encodeOut((uint8_t)2) == 0);
    assert(r3.encodeOut('D') == 'B');
    assert(r3.encodeOut((uint8_t)3) == 1);
    assert(r3.encodeOut('E') == 'C');
    assert(r3.encodeOut((uint8_t)4) == 2);
}

void test_turn() {
    std::vector<sub_t> subs1;
    subs1.push_back(createSub('A', 'B'));
    subs1.push_back(createSub('B', 'D'));
    subs1.push_back(createSub('C', 'C'));
    Rotor r1 = Rotor(subs1, ' ', 'A');

    r1.turn();
    assert(r1.setting == 'B');
    assert(r1.encodeIn('A') == 'C');
    r1.setting = 'Z';
    r1.turn();
    assert(r1.setting == 'A');
    assert(r1.encodeOut('B') == 'A');
}

void test_notchIsEngaged() {
    std::vector<sub_t> subs1;
    subs1.push_back(createSub('A', 'B'));
    subs1.push_back(createSub('B', 'D'));
    subs1.push_back(createSub('C', 'C'));
    Rotor r1 = Rotor(subs1, 'B', 'A');
    r1.turn();
    assert(r1.notchIsEngaged());
}

int main(int argc, char** argv) {
    test_atPosition();
    test_constructors();
    test_positionOf();
    test_encodeIn();
    test_encodeOut();
    test_turn();
    test_notchIsEngaged();

    return 0;
}