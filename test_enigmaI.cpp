#include "enigma.h"

#include <assert.h>

void test_encode() {
    std::vector<sub_t> noSubs;
    EnigmaI e = EnigmaI(noSubs, ENIGMAI_ETW, ENIGMAI_ROTORIII, ENIGMAI_ROTORII, ENIGMAI_ROTORI, ENIGMAI_UKWA, 'A', 'A', 'A');
    assert(e.encode("HELLO WORLD") == "LZFBD EMZWY");
}

void test_turn() {
    std::vector<sub_t> noSubs;
    EnigmaI e1 = EnigmaI(noSubs, ENIGMAI_ETW, ENIGMAI_ROTORIII, ENIGMAI_ROTORII, ENIGMAI_ROTORI, ENIGMAI_UKWA, 'U', 'E', 'Q');
    assert(e1.encode("HELLO WORLD") == "ZFBHA NXSXU");

    EnigmaI e2 = EnigmaI(noSubs, ENIGMAI_ETW, ENIGMAI_ROTORIII, ENIGMAI_ROTORII, ENIGMAI_ROTORI, ENIGMAI_UKWA, 'U', 'D', 'Q');
    assert(e2.encode("HELLO WORLD") == "WFBHA NXSXU");

    EnigmaI e3 = EnigmaI(noSubs, ENIGMAI_ETW, ENIGMAI_ROTORIII, ENIGMAI_ROTORII, ENIGMAI_ROTORI, ENIGMAI_UKWA, 'V', 'E', 'Q');
    assert(e3.encode("HELLO WORLD") == "GUPUU HITGV");
}

int main(int argc, char** argv) {
    test_encode();
    test_turn();

    return 0;
}