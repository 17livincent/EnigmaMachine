#include "rotor.h"

#include <assert.h>
#include <sstream>

Rotor::Rotor() {
    // Substitutions are not scrambled.
    this->setting = 'A';
    this->notch = 'Z';
}

Rotor::Rotor(std::vector<sub_t> subs, char notch, char initialSetting) {
    assert(subs.size() <= MAX_SUBS);
    this->subs = subs;
    this->notch = notch;
    this->setting = initialSetting;
    assert(this->setting >= 'A' && this->setting <= 'Z');
}

Rotor::~Rotor() {
    this->subs.clear();
}

char Rotor::atPosition(uint8_t pos) {
    assert(pos >= 0 && pos <= 25);
    char position = pos + this->setting;
    if(position > 'Z') position -= 26;
    return position;//(char)((pos + this->setting - 'A') % 26) + 'A';
}

uint8_t Rotor::positionOf(char lr) {
    // out and in positions are both relative to the setting and can be calculated the same way
    int8_t pos = 0;
    
    pos = lr - this->setting;
    if(pos < 0) pos += 26;

    return pos;
}

uint8_t Rotor::letterNumber(char lr) {
    return lr - 'A';
}

char Rotor::numberToLetter(uint8_t number) {
    return number + 'A';
}

char Rotor::encodeIn(char r) {
    return this->numberToLetter((int)this->encodeIn(this->letterNumber(r)));
}

uint8_t Rotor::encodeIn(uint8_t inPos) {
    uint8_t encodedPos = inPos;

    char toEncode = this->atPosition(inPos);

    std::vector<sub_t>::iterator subPos;
    for(subPos = this->subs.begin(); subPos != this->subs.end(); subPos++) {
        if(subPos->in == toEncode) {
            break;
        }
    }

    if(subPos != this->subs.end()) {
        int8_t subDiff = subPos->out - toEncode;
        if(subDiff < 0) subDiff += 26;
        encodedPos += subDiff;
        if(encodedPos > 25) encodedPos -= 26;
    }

    return encodedPos;
}

char Rotor::encodeOut(char l) {
    return this->numberToLetter((int)this->encodeOut(this->letterNumber(l)));
}

uint8_t Rotor::encodeOut(uint8_t outPos) {
    char encodedPos = outPos;

    char toEncode = this->atPosition(outPos);

    std::vector<sub_t>::iterator subPos;
    for(subPos = this->subs.begin(); subPos != this->subs.end(); subPos++) {
        if(subPos->out == toEncode) {
            break;
        }
    }

    if(subPos != this->subs.end()) {
        int8_t subDiff = subPos->in - toEncode;
        if(subDiff < 0) subDiff += 26;
        encodedPos += subDiff;
        if(encodedPos >= 26) encodedPos -= 26;
    }

    return encodedPos;
}

void Rotor::turn() {
    this->setting += 1;
    if(this->setting > 'Z') this->setting = 'A';
}

bool Rotor::notchIsEngaged() {
    return this->setting == this->notch;
}

std::string Rotor::toString() {
    std::stringstream ss;

    for(sub_t w : this->subs) {
        ss << w.in << ":" << w.out << " ";
    }

    return ss.str();
}