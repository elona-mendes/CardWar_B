#include <iostream>
#include <stdexcept>
#include <vector>
#include "player.hpp" 

using namespace std;

namespace ariel {
    class Game{
        private: 
            Player& p1;
            Player& p2;
            static const int TOTAL_DECK_SIZE = 52;
            array<string, TOTAL_DECK_SIZE> shflDeck;
            Card deck;
            vector<string> turns;
            int pointerdeck; 
            int drawAmount;

        public:

            // Constructors:
            Game();
            
            Game(Player& pl1, Player& pl2);

            void playTurn();

            int printLastTurn();

            void playAll();

            int printWiner();

            int printLog();

            int printStats();

    };
}