/**
 * @file rotor.h
 * @author Vincent Li (li.vincent0@gmail.com)
 * @brief Defines the Rotor class.
 */

/**
 * Defining some terms:
 *  Position: the number of turns from the current position to the given letter
 *  Left: the side opposite of the reflector
 *  Right: the side facing the reflector
 */

#pragma once
#ifndef ROTOR
#define ROTOR

#include "common.h"

#include <cstdint>
#include <vector>
#include <string>

typedef enum {
    ENIGMAI_ROTORI,
    ENIGMAI_ROTORII,
    ENIGMAI_ROTORIII,
    ENIGMAI_ROTORIV,
    ENIGMAI_ROTORV
} rotor_type;

/**
 * Rotor substitutions are represented by a vector of sub_t's.  The vector has at most 26 elements.
 * If a substitution is not specified in the vector, then it encodes/decodes to the same letter.
 * Only alphabetical characters are encoded.  They must be capitalized.
 */

// Create the known rotor subs
static sub_t rotorDefaultSubsArr[] = {createSub('A', 'A'), createSub('B', 'B'), createSub('C', 'C'), createSub('D', 'D'), createSub('E', 'E'),
                                        createSub('F', 'F'), createSub('G', 'G'), createSub('H', 'H'), createSub('I', 'I'), createSub('J', 'J'),
                                        createSub('K', 'K'), createSub('L', 'L'), createSub('M', 'M'), createSub('N', 'N'), createSub('O', 'O'),
                                        createSub('P', 'P'), createSub('Q', 'Q'), createSub('R', 'R'), createSub('S', 'S'), createSub('T', 'T'),
                                        createSub('U', 'U'), createSub('V', 'V'), createSub('W', 'W'), createSub('X', 'X'), createSub('Y', 'Y'), createSub('Z', 'Z')};
static sub_t rotorIEnigmaISubsArr[] = {createSub('A', 'E'), createSub('B', 'K'), createSub('C', 'M'), createSub('D', 'F'), createSub('E', 'L'),
                                createSub('F', 'G'), createSub('G', 'D'), createSub('H', 'Q'), createSub('I', 'V'), createSub('J', 'Z'),
                                createSub('K', 'N'), createSub('L', 'T'), createSub('M', 'O'), createSub('N', 'W'), createSub('O', 'Y'),
                                createSub('P', 'H'), createSub('Q', 'X'), createSub('R', 'U'), createSub('S', 'S'), createSub('T', 'P'),
                                createSub('U', 'A'), createSub('V', 'I'), createSub('W', 'B'), createSub('X', 'R'), createSub('Y', 'C'), createSub('Z', 'J')};
static sub_t rotorIIEnigmaISubsArr[] = {createSub('A', 'A'), createSub('B', 'J'), createSub('C', 'D'), createSub('D', 'K'), createSub('E', 'S'),
                                    createSub('F', 'I'), createSub('G', 'R'), createSub('H', 'U'), createSub('I', 'X'), createSub('J', 'B'),
                                    createSub('K', 'L'), createSub('L', 'H'), createSub('M', 'W'), createSub('N', 'T'), createSub('O', 'M'),
                                    createSub('P', 'C'), createSub('Q', 'Q'), createSub('R', 'G'), createSub('S', 'Z'), createSub('T', 'N'),
                                    createSub('U', 'P'), createSub('V', 'Y'), createSub('W', 'F'), createSub('X', 'V'), createSub('Y', 'O'), createSub('Z', 'E')};
static sub_t rotorIIIEnigmaISubsArr[] = {createSub('A', 'B'), createSub('B', 'D'), createSub('C', 'F'), createSub('D', 'H'), createSub('E', 'J'),
                                    createSub('F', 'L'), createSub('G', 'C'), createSub('H', 'P'), createSub('I', 'R'), createSub('J', 'T'),
                                    createSub('K', 'X'), createSub('L', 'V'), createSub('M', 'Z'), createSub('N', 'N'), createSub('O', 'Y'),
                                    createSub('P', 'E'), createSub('Q', 'I'), createSub('R', 'W'), createSub('S', 'G'), createSub('T', 'A'),
                                    createSub('U', 'K'), createSub('V', 'M'), createSub('W', 'U'), createSub('X', 'S'), createSub('Y', 'Q'), createSub('Z', 'O')};
static sub_t rotorIVEnigmaISubsArr[] = {createSub('A', 'E'), createSub('B', 'S'), createSub('C', 'O'), createSub('D', 'V'), createSub('E', 'P'),
                                    createSub('F', 'Z'), createSub('G', 'J'), createSub('H', 'A'), createSub('I', 'Y'), createSub('J', 'Q'),
                                    createSub('K', 'U'), createSub('L', 'I'), createSub('M', 'R'), createSub('N', 'H'), createSub('O', 'X'),
                                    createSub('P', 'L'), createSub('Q', 'N'), createSub('R', 'F'), createSub('S', 'T'), createSub('T', 'G'),
                                    createSub('U', 'K'), createSub('V', 'D'), createSub('W', 'C'), createSub('X', 'M'), createSub('Y', 'W'), createSub('Z', 'B')};
static sub_t rotorVEnigmaISubsArr[] = {createSub('A', 'V'), createSub('B', 'Z'), createSub('C', 'B'), createSub('D', 'R'), createSub('E', 'G'),
                                    createSub('F', 'I'), createSub('G', 'T'), createSub('H', 'Y'), createSub('I', 'U'), createSub('J', 'P'),
                                    createSub('K', 'S'), createSub('L', 'D'), createSub('M', 'N'), createSub('N', 'H'), createSub('O', 'L'),
                                    createSub('P', 'X'), createSub('Q', 'A'), createSub('R', 'W'), createSub('S', 'M'), createSub('T', 'J'),
                                    createSub('U', 'Q'), createSub('V', 'O'), createSub('W', 'F'), createSub('X', 'E'), createSub('Y', 'C'), createSub('Z', 'K')};

static std::vector<sub_t> ROTOR_DEFAULT_SUBS(rotorDefaultSubsArr, rotorDefaultSubsArr + sizeof(rotorDefaultSubsArr) / sizeof(sub_t));
static std::vector<sub_t> ENIGMAI_ROTOR_I_SUBS(rotorIEnigmaISubsArr, rotorIEnigmaISubsArr + sizeof(rotorIEnigmaISubsArr) / sizeof(sub_t));
static std::vector<sub_t> ENIGMAI_ROTOR_II_SUBS(rotorIIEnigmaISubsArr, rotorIIEnigmaISubsArr + sizeof(rotorIIEnigmaISubsArr) / sizeof(sub_t));
static std::vector<sub_t> ENIGMAI_ROTOR_III_SUBS(rotorIIIEnigmaISubsArr, rotorIIIEnigmaISubsArr + sizeof(rotorIIIEnigmaISubsArr) / sizeof(sub_t));
static std::vector<sub_t> ENIGMAI_ROTOR_IV_SUBS(rotorIVEnigmaISubsArr, rotorIVEnigmaISubsArr + sizeof(rotorIVEnigmaISubsArr) / sizeof(sub_t));
static std::vector<sub_t> ENIGMAI_ROTOR_V_SUBS(rotorVEnigmaISubsArr, rotorVEnigmaISubsArr + sizeof(rotorVEnigmaISubsArr) / sizeof(sub_t));

// Known rotor notch positions
static const char ENIGMAI_ROTOR_I_NOTCH = 'Q';
static const char ENIGMAI_ROTOR_II_NOTCH = 'E';
static const char ENIGMAI_ROTOR_III_NOTCH = 'V';
static const char ENIGMAI_ROTOR_IV_NOTCH = 'J';
static const char ENIGMAI_ROTOR_V_NOTCH = 'Z';

static const int MAX_SUBS = 26; // letters in alphabet

class Rotor {
    public:
        // The right position at which the notch is located [A,Z]
        char notch;
        // The rotor's (initial) setting, which is a right letter; increments as the rotor turns [A,Z]
        char setting;
        // Substitutions
        std::vector<sub_t> subs;

        /**
         * @brief Default constructor which creates a rotor with no notch, 
         * and the wiring is not scrambled.
         * The initial setting is A.
         */
        Rotor();

        /**
         * @brief Create a rotor with the given wiring and notch.
         * @param subs the substitutions with the right letters in alphabetical, ascending order
         * @param notch the right letter where the notch is located
         * @param initialSetting the starting position of the rotor
         */
        Rotor(std::vector<sub_t> subs, char notch, char initialSetting);

        // Destructor
        ~Rotor();

        /**
         * @brief Get the letter at the given position.
         * 
         * @param pos 
         * @return char 
         */
        char atPosition(uint8_t pos);

        /**
         * @brief Get the position of the given left/right letter
         * @param left 
         * @return uint8_t the position, which is relative to the current setting
         */
        uint8_t positionOf(char lr);

        uint8_t letterNumber(char lr);

        char numberToLetter(uint8_t number);

        /**
         * @brief Get the letter paired with the given right one.  
         * If the substitution for the right letter doesn't exist, return the same letter.
         * @param right the right letter
         * @return char the left letter
         */
        char encodeIn(char right);

        /**
         * @brief Get the position of the left letter encoded by the letter at the right position.
         * 
         * @param rightPos the position of the right letter
         * @return char the left letter's position
         */
        uint8_t encodeIn(uint8_t rightPos);

        /**
         * @brief Get the letter paired with the given left one.
         * @param left the left letter
         * @return char the right letter
         */
        char encodeOut(char left);

        /**
         * @brief Get the position of the right letter encoded by the letter at the left position.
         * 
         * @param leftPos the position of the left letter
         * @return uint8_t the right letter's position
         */
        uint8_t encodeOut(uint8_t leftPos);

        /**
         * @brief Rotates the rotor by 1 position.  Moves the current setting "up".
         */
        void turn();

        /**
         * @brief Returns if the current position is the notch position, meaning that the next rotor needs to turn.
         * 
         * @return true 
         * @return false 
         */
        bool notchIsEngaged();

        /**
         * @brief Get string representation of the rotor.
         * 
         * @return std::string 
         */
        std::string toString();
};

// Classes for known rotors
class EnigmaIRotorI: public Rotor {
    public:
        EnigmaIRotorI(char initialSetting): Rotor(ENIGMAI_ROTOR_I_SUBS, ENIGMAI_ROTOR_I_NOTCH, initialSetting) {};
};

class EnigmaIRotorII: public Rotor {
    public:
        EnigmaIRotorII(char initialSetting): Rotor(ENIGMAI_ROTOR_II_SUBS, ENIGMAI_ROTOR_II_NOTCH, initialSetting) {};
};

class EnigmaIRotorIII: public Rotor {
    public:
        EnigmaIRotorIII(char initialSetting): Rotor(ENIGMAI_ROTOR_III_SUBS, ENIGMAI_ROTOR_III_NOTCH, initialSetting) {};
};

class EnigmaIRotorIV: public Rotor {
    public:
        EnigmaIRotorIV(char initialSetting): Rotor(ENIGMAI_ROTOR_IV_SUBS, ENIGMAI_ROTOR_IV_NOTCH, initialSetting) {};
};

class EnigmaIRotorV: public Rotor {
    public:
        EnigmaIRotorV(char initialSetting): Rotor(ENIGMAI_ROTOR_V_SUBS, ENIGMAI_ROTOR_V_NOTCH, initialSetting) {};
};

#endif  // ROTOR