# Enigma 1

This C++ project is an Enigma machine simulator.  It implements specifically the Enigma I, but additional machines can be easily created with the defined Plugboard, Rotor, Reflector, Entrywheel, and Enigma classes.

## Usage
### Enigma I
1. Modify the machine's settings in ```run_enigmaI.cpp``` (no fancy CLI at the moment)
2. Run ```make run_enigmaI```
2. To encode/decode a message, use something like ```./run_enigmaI "MESSAGE IN ALL CAPS"```

## Critical Components
 - Plugboard
 - Entry wheel (aka ETW)
 - Rotors
 - Reflector (aka UKW)

## Prospective Features
- Rotors with multiple notch positions
- Other Enigma variants
- CLI includes Enigma settings

## Enigma 1 Wiring Details
Wheel:  ABCDEFGHIJKLMNOPQRSTUVWXYZ  Turnover (right letter)

ETW:    ABCDEFGHIJKLMNOPQRSTUVWXYZ

I:      EKMFLGDQVZNTOWYHXUSPAIBRCJ  Q

II:     AJDKSIRUXBLHWTMCQGZNPYFVOE  E

III:    BDFHJLCPRTXVZNYEIWGAKMUSQO  V

IV:     ESOVPZJAYQUIRHXLNFTGKDCMWB  J

V:      VZBRGITYUPSDNHLXAWMJQOFECK  Z

UKW-A:  EJMZALYXVBWFCRQUONTSPIKHGD

UKW-B:  YRUHQSLDPXNGOKMIEBFZCWVJAT

UKW-C:  FVPJIAOYEDRZXWGCTKUQSBNMHL

## References
https://en.wikipedia.org/wiki/Enigma_machine
https://en.wikipedia.org/wiki/Enigma_rotor_details
https://www.cryptomuseum.com/crypto/enigma/i/index.htm
http://users.telenet.be/d.rijmenants/en/enigmatech.ht
