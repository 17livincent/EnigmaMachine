/**
 * @file reflector.h
 * @author Vincent Li (li.vincent0@gmail.com)
 * @brief The Enigma machine reflector 
 * which feeds the line back through the reflectors.
 * The permanent setting is the 'A' position.
 */

#pragma once
#ifndef REFLECTOR
#define REFLECTOR

#include "common.h"

#include <cstdint>
#include <vector>
#include <string>

typedef enum {
    ENIGMAI_UKWA,
    ENIGMAI_UKWB,
    ENIGMAI_UKWC
} reflector_type;

static sub_t reflectorDefaultSubsArr[] = {createSub('A', 'A'), createSub('B', 'B'), createSub('C', 'C'), createSub('D', 'D'), createSub('E', 'E'),
                                            createSub('F', 'F'), createSub('G', 'G'), createSub('H', 'H'), createSub('I', 'I'), createSub('J', 'J'),
                                            createSub('K', 'K'), createSub('L', 'L'), createSub('M', 'M'), createSub('N', 'N'), createSub('O', 'O'),
                                            createSub('P', 'P'), createSub('Q', 'Q'), createSub('R', 'R'), createSub('S', 'S'), createSub('T', 'T'),
                                            createSub('U', 'U'), createSub('V', 'V'), createSub('W', 'W'), createSub('X', 'X'), createSub('Y', 'Y'), createSub('Z', 'Z')};
static sub_t reflectorEnigmaIASubsArr[] = {createSub('A', 'E'), createSub('B', 'J'), createSub('C', 'M'), createSub('D', 'Z'), createSub('E', 'A'),
                                            createSub('F', 'L'), createSub('G', 'Y'), createSub('H', 'X'), createSub('I', 'V'), createSub('J', 'B'),
                                            createSub('K', 'W'), createSub('L', 'F'), createSub('M', 'C'), createSub('N', 'R'), createSub('O', 'Q'),
                                            createSub('P', 'U'), createSub('Q', 'O'), createSub('R', 'N'), createSub('S', 'T'), createSub('T', 'S'),
                                            createSub('U', 'P'), createSub('V', 'I'), createSub('W', 'K'), createSub('X', 'H'), createSub('Y', 'G'), createSub('Z', 'D')};
static sub_t reflectorEnigmaIBSubsArr[] = {createSub('A', 'Y'), createSub('B', 'R'), createSub('C', 'U'), createSub('D', 'H'), createSub('E', 'Q'),
                                            createSub('F', 'S'), createSub('G', 'L'), createSub('H', 'D'), createSub('I', 'P'), createSub('J', 'X'),
                                            createSub('K', 'N'), createSub('L', 'G'), createSub('M', 'O'), createSub('N', 'K'), createSub('O', 'M'),
                                            createSub('P', 'I'), createSub('Q', 'E'), createSub('R', 'B'), createSub('S', 'F'), createSub('T', 'Z'),
                                            createSub('U', 'C'), createSub('V', 'W'), createSub('W', 'V'), createSub('X', 'J'), createSub('Y', 'A'), createSub('Z', 'T')};
static sub_t reflectorEnigmaICSubsArr[] = {createSub('A', 'F'), createSub('B', 'V'), createSub('C', 'P'), createSub('D', 'J'), createSub('E', 'I'),
                                            createSub('F', 'A'), createSub('G', 'O'), createSub('H', 'Y'), createSub('I', 'E'), createSub('J', 'D'),
                                            createSub('K', 'R'), createSub('L', 'Z'), createSub('M', 'X'), createSub('N', 'W'), createSub('O', 'G'),
                                            createSub('P', 'C'), createSub('Q', 'T'), createSub('R', 'K'), createSub('S', 'U'), createSub('T', 'Q'),
                                            createSub('U', 'S'), createSub('V', 'B'), createSub('W', 'N'), createSub('X', 'M'), createSub('Y', 'H'), createSub('Z', 'L')};

static std::vector<sub_t> REFLECTOR_DEFAULT_SUBS(reflectorDefaultSubsArr, reflectorDefaultSubsArr + sizeof(reflectorDefaultSubsArr) / sizeof(sub_t));
static std::vector<sub_t> ENIGMAI_REFLECTOR_A_SUBS(reflectorEnigmaIASubsArr, reflectorEnigmaIASubsArr + sizeof(reflectorEnigmaIASubsArr) / sizeof(sub_t));
static std::vector<sub_t> ENIGMAI_REFLECTOR_B_SUBS(reflectorEnigmaIBSubsArr, reflectorEnigmaIBSubsArr + sizeof(reflectorEnigmaIBSubsArr) / sizeof(sub_t));
static std::vector<sub_t> ENIGMAI_REFLECTOR_C_SUBS(reflectorEnigmaICSubsArr, reflectorEnigmaICSubsArr + sizeof(reflectorEnigmaICSubsArr) / sizeof(sub_t));

class Reflector {
    public:
        // Reflector's substitutions
        std::vector<sub_t> subs;

        /**
         * @brief Create a reflector with no substitutions.
         */
        Reflector();

        /**
         * @brief Create a reflector with the given substitutions.
         */
        Reflector(std::vector<sub_t> subs);

        ~Reflector();

        /**
         * @brief Get the position the given one encodes to.
         * 
         * @return uint8_t the encoded position
         */
        uint8_t encode(uint8_t pos);

        /**
         * @brief Get a string representation of the reflector
         * 
         * @return std::string 
         */
        std::string toString();
};

// Classes for known reflectors
class EnigmaIReflectorA: public Reflector {
    public:
        EnigmaIReflectorA(): Reflector(ENIGMAI_REFLECTOR_A_SUBS) {};
};

class EnigmaIReflectorB: public Reflector {
    public:
        EnigmaIReflectorB(): Reflector(ENIGMAI_REFLECTOR_B_SUBS) {};
};

class EnigmaIReflectorC: public Reflector {
    public:
        EnigmaIReflectorC(): Reflector(ENIGMAI_REFLECTOR_C_SUBS) {};
};

#endif  // REFLECTOR