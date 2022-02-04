#pragma once
#ifndef COMMON
#define COMMON

/**
 * @brief Substitution struct.
 * Represents all substitutions/transitions for 
 * the plugboard, entrywheel, rotors, and reflector.
 * 
 */
struct sub_t {
    char in = 0;
    char out = 0;
};

sub_t createSub(char i, char o);

#endif  // COMMON