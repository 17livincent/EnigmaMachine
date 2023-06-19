/**
 * @file plugboard.h
 * @author Vincent Li (li.vincent0@gmail.com)
 * @brief Defines the class that represents the plugboard.
 * 
 * The plugboard lets the user manually swap letter pairs.
 * 10 swaps (wires) max are traditionally used.
 * If a wire is not located at a letter, then the decoded letter is the same one.
 */

#pragma once
#ifndef PLUGBOARD
#define PLUGBOARD

#include "common.h"

#include <vector>
#include <string>

static const int MAX_WIRES = 10;

class Plugboard {
    public:
        // A vector of wires
        std::vector<sub_t> wires;

        /**
         * @brief Default constructor for an empty plugboard.
         */
        Plugboard();

        /**
         * @brief Constructor with a map of wires as the input.
         * @param wires the vector of letter-letter pairs.
         */
        Plugboard(std::vector<sub_t> wires);

        // Destructor
        ~Plugboard();

        /**
         * @brief Encode the given letter on its way into the machine.         * @param letter The letter to encode
         * @return char The encoded letter
         */
        char encodeIn(char letter);

        /**
         * @brief Encode the given letter on its way out of the machine.         * @param letter The letter to encode
         * @return char The encoded letter
         */
        char encodeOut(char letter);

        /**
         * @brief Add a wire to the plugboard.
         * 
         * @param wire 
         * @return true if successful
         * @return false if unsuccessful
         */
        bool addWire(sub_t wire);

        /**
         * @brief Remove a wire from the plugboard.
         * 
         * @param i the input letter
         * @param o the output letter
         * @return true if successful
         * @return false if unsuccessful
         */
        bool removeWire(char i, char o);

        /**
         * @brief Get a string representation of the plugboard.
         * 
         * @return std::string 
         */
        std::string toString();
};

#endif  // PLUGBOARD