#include "plugboard.h"

#include <assert.h>

void test_constructors() {
    // Default
    Plugboard p1 = Plugboard();
    assert(p1.wires.size() == 0);

    // Overloaded
    std::vector<sub_t> wires;
    wires.push_back(createSub('A', 'B'));
    wires.push_back(createSub('C', 'D'));
    wires.push_back(createSub('E', 'F'));
    wires.push_back(createSub('G', 'H'));
    wires.push_back(createSub('I', 'J'));
    wires.push_back(createSub('K', 'L'));
    wires.push_back(createSub('M', 'N'));
    wires.push_back(createSub('O', 'P'));
    wires.push_back(createSub('Q', 'R'));
    wires.push_back(createSub('S', 'T'));
    Plugboard p2 = Plugboard(wires);
    assert(p2.wires.size() == MAX_WIRES);
}

void test_encodeIn() {
    std::vector<sub_t> wires;
    wires.push_back(createSub('A', 'B'));
    Plugboard p = Plugboard(wires);
    assert(p.encodeIn('A') == 'B');
    assert(p.encodeIn('Z') == 'Z'); // wire not at 'Z'
}

void test_encodeOut() {
    std::vector<sub_t> wires;
    wires.push_back(createSub('A', 'B'));
    Plugboard p = Plugboard(wires);
    assert(p.encodeOut('B') == 'A');
    assert(p.encodeIn('Z') == 'Z'); // wire not at 'Z'
}

void test_addWire() {
    Plugboard p = Plugboard();
    assert(p.addWire(createSub('A', 'B')));
    assert(p.wires.size() == 1);
    // Try adding a wire to a letter that is already plugged in
    assert(p.addWire(createSub('A', 'C')) == false);
    assert(p.addWire(createSub('B', 'A')) == false);
    assert(p.addWire(createSub('C', 'A')) == false);
    // Add as many wires as allowed
    assert(p.addWire(createSub('C', 'D')));
    assert(p.addWire(createSub('E', 'F')));
    assert(p.addWire(createSub('G', 'H')));
    assert(p.addWire(createSub('I', 'J')));
    assert(p.addWire(createSub('K', 'L')));
    assert(p.addWire(createSub('M', 'N')));
    assert(p.addWire(createSub('O', 'P')));
    assert(p.addWire(createSub('Q', 'R')));
    assert(p.addWire(createSub('S', 'T')));
    // Add more than the max
    assert(p.addWire(createSub('U', 'V')) == false);
}

void test_removeWire() {
    Plugboard p = Plugboard();
    assert(p.addWire(createSub('A', 'B')));
    // Remove non-existent wires
    assert(p.removeWire('X', 'Z') == false);
    assert(p.removeWire('A', 'C') == false);
    assert(p.removeWire('C', 'B') == false);
    // Remove a valid wire
    assert(p.removeWire('A', 'B'));
    // Remove when there are no more
    assert(p.removeWire('A', 'B') == false);
}

int main(int argc, char** argv) {
    test_constructors();
    test_encodeIn();
    test_encodeOut();
    test_addWire();
    test_removeWire();
}