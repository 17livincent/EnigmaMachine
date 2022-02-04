/**
 * @file entrywheel.h
 * @author Vincent Li (li.vincent0@gmail.com)
 * @brief Implements the entry wheel, which is set between the plugboard and first rotor.
 */

#pragma once
#ifndef ENTRYWHEEL
#define ENTRYWHEEL

#include "common.h"

#include <cstdint>
#include <vector>
#include <string>

typedef enum {
    ENIGMAI_ETW
} entrywheel_type;

// Known entrywheel substitutions
static sub_t ewDefaultSubsArr[] = {createSub('A', 'A'), createSub('B', 'B'), createSub('C', 'C'), createSub('D', 'D'), createSub('E', 'E'),
                                    createSub('F', 'F'), createSub('G', 'G'), createSub('H', 'H'), createSub('I', 'I'), createSub('J', 'J'),
                                    createSub('K', 'K'), createSub('L', 'L'), createSub('M', 'M'), createSub('N', 'N'), createSub('O', 'O'),
                                    createSub('P', 'P'), createSub('Q', 'Q'), createSub('R', 'R'), createSub('S', 'S'), createSub('T', 'T'),
                                    createSub('U', 'U'), createSub('V', 'V'), createSub('W', 'W'), createSub('X', 'X'), createSub('Y', 'Y'), createSub('Z', 'Z')};
static sub_t ewEnigmaISubsArr[] = {createSub('A', 'A'), createSub('B', 'B'), createSub('C', 'C'), createSub('D', 'D'), createSub('E', 'E'),
                                    createSub('F', 'F'), createSub('G', 'G'), createSub('H', 'H'), createSub('I', 'I'), createSub('J', 'J'),
                                    createSub('K', 'K'), createSub('L', 'L'), createSub('M', 'M'), createSub('N', 'N'), createSub('O', 'O'),
                                    createSub('P', 'P'), createSub('Q', 'Q'), createSub('R', 'R'), createSub('S', 'S'), createSub('T', 'T'),
                                    createSub('U', 'U'), createSub('V', 'V'), createSub('W', 'W'), createSub('X', 'X'), createSub('Y', 'Y'), createSub('Z', 'Z')};

static std::vector<sub_t> EW_DEFAULT_SUBS(ewDefaultSubsArr, ewDefaultSubsArr + sizeof(ewDefaultSubsArr) / sizeof(sub_t));
static std::vector<sub_t> ENIGMAI_EW_SUBS(ewEnigmaISubsArr, ewEnigmaISubsArr + sizeof(ewEnigmaISubsArr) / sizeof(sub_t));

class EntryWheel {
    public:
        std::vector<sub_t> subs;

        /**
         * @brief Create an entrywheel with no substitutions.
         * This will be used for Enigma 1.
         */
        EntryWheel();

        /**
         * @brief Create an entrywheel with the given substitutions.
         */
        EntryWheel(std::vector<sub_t> subs);

        ~EntryWheel();

        /**
         * @brief Encode the letter from the plugboard.
         * @param letter 
         * @return uint8_t the position of the encoded letter
         */
        uint8_t encodeIn(char letter);

        /**
         * @brief Encode the letter of the given position from the first rotor.
         * @param pos which is always relative to 'A' 
         * @return char the encoded letter
         */
        char encodeOut(uint8_t pos);

        /**
         * @brief Get a string representation of the entrywheel.
         * @return std::string 
         */
        std::string toString();
};

class EnigmaIEntryWheel: public EntryWheel {
    public:
        EnigmaIEntryWheel(): EntryWheel(ENIGMAI_EW_SUBS) {};
};

#endif  // ENTRYWHEEL