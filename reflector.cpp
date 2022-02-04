#include "reflector.h"

#include <cassert>
#include <sstream>

Reflector::Reflector() {}

Reflector::Reflector(std::vector<sub_t> subs) {
    assert(subs.size() <= 26);
    this->subs = subs;
}

Reflector::~Reflector() {
    this->subs.clear();
}

uint8_t Reflector::encode(uint8_t pos) {
    // Setting is always 'A'
    uint8_t encoded = pos;

    std::vector<sub_t>::iterator subPos;
    for(subPos = this->subs.begin(); subPos != this->subs.end(); subPos++) {
        if(subPos->in == pos + 'A') {
            break;
        }
    }

    if(subPos != this->subs.end()) {
        encoded = subPos->out - 'A';
    }

    return encoded;
}

std::string Reflector::toString() {
    std::stringstream ss;

    for(sub_t w : this->subs) {
        ss << w.in << ":" << w.out << " ";
    }

    return ss.str();
}