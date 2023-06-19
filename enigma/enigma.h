/**
 * @file enigma.h
 * @author Vincent Li (li.vincent0@gmail.com)
 * @brief Parent class of all Enigma machines.  
 * Declares some virtual functions.
 */

#pragma once
#ifndef ENIGMA
#define ENIGMA

#include "plugboard.h"
#include "entrywheel.h"
#include "rotor.h"
#include "reflector.h"

#include <string>
#include <iostream>

class Enigma {
    public:
        /**
         * @brief Encode the given character
         * @param c 
         * @return char 
         */
        virtual char encode(char c) {
            std::cout << "Dummy function called." << std::endl;
            return 0;
        }

        /**
         * @brief Encode the given string
         * @param s 
         * @return std::string 
         */
        virtual std::string encode(std::string s) {
            std::cout << "Dummy function called." << std::endl;
            return "";
        }
};

class EnigmaI : public Enigma {
    public:
        // Components
        Plugboard plugboard;
        EntryWheel entrywheel;
        Rotor rotorR;
        Rotor rotorM;
        Rotor rotorL;
        Reflector reflector;

        /**
         * @brief Construct a new Enigma I object
         * 
         * @param plugboardWires vector of plugboard substitutions
         * @param etw entrywheel type
         * @param rotorL left rotor type
         * @param rotorM middle rotor type
         * @param rotorR right rotor type
         * @param reflector reflector type
         * @param rotorLSetting left rotor setting
         * @param rotorMSetting middle rotor setting
         * @param rotorRSetting right rotor setting
         */
        EnigmaI(std::vector<sub_t> plugboardWires, 
            entrywheel_type etw, 
            rotor_type rotorL, 
            rotor_type rotorM, 
            rotor_type rotorR, 
            reflector_type reflector,
            char rotorLSetting, 
            char rotorMSetting, 
            char rotorRSetting);

        virtual char encode(char c);
        virtual std::string encode(std::string s);
};

#endif  // ENIGMA