#include "entrywheel.h"

#include <assert.h>
#include <sstream>

EntryWheel::EntryWheel() {}

EntryWheel::EntryWheel(std::vector<sub_t> subs) {
    assert(subs.size() <= 26);
    this->subs = subs;
}

EntryWheel::~EntryWheel() {
    this->subs.clear();
}

uint8_t EntryWheel::encodeIn(char letter) {
    assert(letter <= 'Z' && letter >= 'A');
    uint8_t encoded = letter - 'A';

    std::vector<sub_t>::iterator subPos;
    for(subPos = this->subs.begin(); subPos != this->subs.end(); subPos++) {
        if(subPos->in == letter) {
            break;
        }
    }

    if(subPos != this->subs.end()) {
        encoded = subPos->out - 'A';
    }

    return encoded;
}

char EntryWheel::encodeOut(uint8_t pos) {
    assert(pos >= 0 && pos <= 25);
    char encoded = pos + 'A';

    std::vector<sub_t>::iterator subPos;
    for(subPos = this->subs.begin(); subPos != this->subs.end(); subPos++) {
        if(subPos->out == pos + 'A') {
            break;
        }
    }

    if(subPos != this->subs.end()) {
        encoded = subPos->in;
    }

    return encoded;
}

std::string EntryWheel::toString() {
    std::stringstream ss;

    for(sub_t w : this->subs) {
        ss << w.in << ":" << w.out << " ";
    }

    return ss.str();
}