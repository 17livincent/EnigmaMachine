/**
 * @file run_enigmaI.cpp
 * @author Vincent Li (li.vincent0@gmail.com)
 * @brief Executable for Enigma I.
 * argv[1] is the message to encode/decode in quotes ("ENCODE THIS")
 */

#include "enigma.h"

#include <string>
#include <iostream>

std::string processInput(std::string input) {
    std::string processed = "";

    for(long unsigned int i = 0; i < input.length(); i++) {
        // If lowercase, convert to uppercase
        char c = input[i];
        if(c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        }

        processed += c;
    }

    return processed;
}

int main(int argc, char** argv) {
    // Create an Enigma I machine
    // No fancy command line input yet for machine settings

    std::vector<sub_t> plugboardSubs;   // Plugboard substitutions
    entrywheel_type etw = ENIGMAI_ETW;  // Entrywheel
    rotor_type rR = ENIGMAI_ROTORI;     // Right rotor
    rotor_type rM = ENIGMAI_ROTORII;    // Middle rotor
    rotor_type rL = ENIGMAI_ROTORIII;   // Left rotor
    reflector_type ref = ENIGMAI_UKWA;  // Reflector
    char rRSetting = 'A';               // Right rotor setting
    char rMSetting = 'A';               // Middle rotor setting
    char rLSetting = 'A';               // Left rotor setting
    EnigmaI e = EnigmaI(plugboardSubs, etw, rL, rM, rR, ref, rLSetting, rMSetting, rRSetting);

    std::string input(argv[1]);
    std::cout << e.encode(processInput(input)) << std::endl;
}