#include "entrywheel.h"

#include <cassert>

void test_constructors() {
    EntryWheel e1 = EntryWheel();
    assert(e1.subs.size() == 0);

    std::vector<sub_t> subs;
    subs.push_back(createSub('A', 'B'));
    subs.push_back(createSub('B', 'C'));
    subs.push_back(createSub('C', 'D'));
    subs.push_back(createSub('D', 'E'));
    EntryWheel e2 = EntryWheel(subs);
    assert(e2.subs.size() == 4);
}

void test_encodeIn() {
    std::vector<sub_t> subs;
    subs.push_back(createSub('A', 'B'));
    subs.push_back(createSub('B', 'C'));
    subs.push_back(createSub('C', 'D'));
    subs.push_back(createSub('D', 'E'));
    EntryWheel e1 = EntryWheel(subs);

    assert(e1.encodeIn('A') == 1u);
    assert(e1.encodeIn('B') == 2u);
    assert(e1.encodeIn('E') == 4u);
}

void test_encodeOut() {
    std::vector<sub_t> subs;
    subs.push_back(createSub('A', 'B'));
    subs.push_back(createSub('B', 'C'));
    subs.push_back(createSub('C', 'D'));
    subs.push_back(createSub('D', 'E'));
    EntryWheel e1 = EntryWheel(subs);

    assert(e1.encodeOut(1) == 'A');
    assert(e1.encodeOut(2) == 'B');
    assert(e1.encodeOut(4) == 'D');
}

int main(int argc, char** argv) {
    test_constructors();
    test_encodeIn();
    test_encodeOut();
}