#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include "card.hpp"

// some_header_file.h
// #ifndef CARD_H
// #define CARD_H

using namespace std;
using namespace ariel;

// array<string, 52> Card::deckShuffling(){
//     // Shuffle deck
//     srand(time(0));
//     for (int i = 0; i < 52; i++) {
//         int j = rand() % 52;
//         string temp = this->deck1[i];
//         this->deck1[i] = this->deck1[j];
//         this->deck1[j] = temp;
//     }
//     return this->deck1;
// }


string* Card::deckShuffling(){
    // Shuffle deck
    srand(time(0));
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        string temp = this->deck[i];
        this->deck[i] = this->deck[j];
        this->deck[j] = temp;
    }
    return this->deck;
}

// your code
// #endif