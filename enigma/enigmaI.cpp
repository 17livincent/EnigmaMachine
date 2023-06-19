#include "enigma.h"

EnigmaI::EnigmaI(std::vector<sub_t> plugboardWires, 
            entrywheel_type etw, 
            rotor_type rotorL, 
            rotor_type rotorM, 
            rotor_type rotorR, 
            reflector_type reflector,
            char rotorLSetting, 
            char rotorMSetting, 
            char rotorRSetting) {
    // Create the plugboard
    this->plugboard = Plugboard(plugboardWires);
    // Create the entrywheel
    this->entrywheel = EnigmaIEntryWheel();
    // Create the left rotor
    switch(rotorL) {
        case ENIGMAI_ROTORI:
            this->rotorL = EnigmaIRotorI(rotorLSetting);
            break;
        case ENIGMAI_ROTORII:
            this->rotorL = EnigmaIRotorII(rotorLSetting);
            break;
        case ENIGMAI_ROTORIII:
            this->rotorL = EnigmaIRotorIII(rotorLSetting);
            break;
        case ENIGMAI_ROTORIV:
            this->rotorL = EnigmaIRotorIV(rotorLSetting);
            break;
        case ENIGMAI_ROTORV:
            this->rotorL = EnigmaIRotorV(rotorLSetting);
            break;
    }
    // Create the middle rotor
    switch(rotorM) {
        case ENIGMAI_ROTORI:
            this->rotorM = EnigmaIRotorI(rotorMSetting);
            break;
        case ENIGMAI_ROTORII:
            this->rotorM = EnigmaIRotorII(rotorMSetting);
            break;
        case ENIGMAI_ROTORIII:
            this->rotorM = EnigmaIRotorIII(rotorMSetting);
            break;
        case ENIGMAI_ROTORIV:
            this->rotorM = EnigmaIRotorIV(rotorMSetting);
            break;
        case ENIGMAI_ROTORV:
            this->rotorM = EnigmaIRotorV(rotorMSetting);
            break;
    }
    // Create the right rotor
    switch(rotorR) {
        case ENIGMAI_ROTORI:
            this->rotorR = EnigmaIRotorI(rotorRSetting);
            break;
        case ENIGMAI_ROTORII:
            this->rotorR = EnigmaIRotorII(rotorRSetting);
            break;
        case ENIGMAI_ROTORIII:
            this->rotorR = EnigmaIRotorIII(rotorRSetting);
            break;
        case ENIGMAI_ROTORIV:
            this->rotorR = EnigmaIRotorIV(rotorRSetting);
            break;
        case ENIGMAI_ROTORV:
            this->rotorR = EnigmaIRotorV(rotorRSetting);
            break;
    }
    // Create the reflector
    switch(reflector) {
        case ENIGMAI_UKWA:
            this->reflector = EnigmaIReflectorA();
            break;
        case ENIGMAI_UKWB:
            this->reflector = EnigmaIReflectorB();
            break;
        case ENIGMAI_UKWC:
            this->reflector = EnigmaIReflectorC();
            break;
    }
}

char EnigmaI::encode(char c) {
    if(c >= 'A' && c <= 'Z') {  // Only try to encode if  alphabetical and uppercase
        // Increment rotors
        if(rotorM.notchIsEngaged()) {
            rotorL.turn();
            rotorM.turn();
        }
        else if(rotorR.notchIsEngaged()) rotorM.turn();
        rotorR.turn();

        // Encode the letter
        // Forward pass
        char encoded1 = this->plugboard.encodeIn(c);
        uint8_t encoded2 = this->entrywheel.encodeIn(encoded1);
        uint8_t encoded3 = this->rotorR.encodeIn((uint8_t)(encoded2));
        uint8_t encoded4 = this->rotorM.encodeIn((uint8_t)encoded3);
        uint8_t encoded5 = this->rotorL.encodeIn((uint8_t)encoded4);
        uint8_t encoded6 = this->reflector.encode((uint8_t)encoded5);
        // Backward pass
        uint8_t encoded7 = this->rotorL.encodeOut((uint8_t)encoded6);
        uint8_t encoded8 = this->rotorM.encodeOut((uint8_t)encoded7);
        uint8_t encoded9 = this->rotorR.encodeOut((uint8_t)encoded8);
        uint8_t encoded10 = this->entrywheel.encodeOut((uint8_t)encoded9);
        char encodedFinal = this->plugboard.encodeOut(encoded10);

        return encodedFinal;
    }
    else {
        return c;
    }
}

std::string EnigmaI::encode(std::string s) {
    std::string encoded = "";

    for(long unsigned int i = 0; i < s.length(); i++) {
        encoded += this->encode(s[i]);
    }

    return encoded;
}