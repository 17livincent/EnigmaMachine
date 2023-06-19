#include "plugboard.h"

#include <sstream>
#include <assert.h>

Plugboard::Plugboard() {};

Plugboard::Plugboard(std::vector<sub_t> wires) {
    assert(wires.size() <= MAX_WIRES);
    this->wires = wires;
}

Plugboard::~Plugboard() {
    this->wires.clear();
}

char Plugboard::encodeIn(char letter) {
    char encoded = letter;
    
    // Find "in" letter in wires
    std::vector<sub_t>::iterator loc;
    for(loc = this->wires.begin(); loc != this->wires.end(); loc++) {
        if(loc->in == letter) {
            break;
        }
    }
    
    // if there is no wire at the letter, return the letter
    if(loc != this->wires.end()) {
        encoded = loc->out;
    }

    return encoded;
}

char Plugboard::encodeOut(char letter) {
    char encoded = letter;
    
    // Find the "out" letter in wires
    std::vector<sub_t>::iterator loc;
    for(loc = this->wires.begin(); loc != this->wires.end(); loc++) {
        if(loc->out == letter) {
            break;
        }
    }

    // if there is no wire at the letter, return the letter
     if(loc != this->wires.end()) {
        encoded = loc->in;
    }

    return encoded;
}

bool Plugboard::addWire(sub_t wire) {
    bool result = true;
    // Num of wires cannot be max already
    if(this->wires.size() == MAX_WIRES) result = false;
    // Any of the letters in the wire cannot already be plugged into
    for(auto w : this->wires) {
        if(w.in == wire.in || w.out == wire.out || w.in == wire.out || w.out == wire.in) {
            result = false;
            break;
        }
    }

    if(result == true) {    // Add the wire
        this->wires.push_back(wire);
    }

    return result;
}

bool Plugboard::removeWire(char i, char o) {
    sub_t wire = createSub(i, o);
    bool result = false;

    // If the wire exists, remove it
    std::vector<sub_t>::iterator loc;
    for(loc = this->wires.begin(); loc != this->wires.end(); loc++) {
        if(wire.in == loc->in && wire.out == loc->out) {
            break;
        }
    }

    if(loc != this->wires.end()) {
        result = true;
        this->wires.erase(loc);
    }

    return result;
}

std::string Plugboard::toString() {
    std::stringstream ss;

    for(sub_t w : this->wires) {
        ss << w.in << ":" << w.out << " ";
    }

    return ss.str();
}