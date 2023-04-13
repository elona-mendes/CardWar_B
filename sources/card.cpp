#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include "card.hpp"

using namespace std;
using namespace ariel;

array<string, 52> Card::deckShuffling(){

    std::random_device rd;
    std::mt19937 g(rd());
    // Shuffle deck
    std::shuffle(this->deck1.begin(), this->deck1.end(), g);

    return this->deck1;
}