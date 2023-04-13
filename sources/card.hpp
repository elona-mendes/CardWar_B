#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <array>

#include <algorithm>
#include <random>

using namespace std;

#ifndef CARD_H
#define CARD_H

namespace ariel {
    class Card{
      
        private:
        //14 is As. 11, 12, 13 are the symbols(king, queen... )
        //H = Hearts, D = Diamonds, C = Clubs, S = Spades.
        static const int TOTAL_DECK_SIZE = 52;
        std::array<string, TOTAL_DECK_SIZE> deck1{{"14H", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "11H", "12H", "13H",
                            "14D", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "11D", "12D", "13D", 
                            "14C","2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "11C", "12C", "13C", 
                            "14S", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "11S", "12S", "13S"}};  
                            
        public:
            // Shuffling the deck
            array<string, TOTAL_DECK_SIZE> deckShuffling();
    };

};
#endif
