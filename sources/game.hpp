#include <iostream>
#include <stdexcept>
#include <vector>
#include "player.hpp" 

using namespace std;

namespace ariel {
    class Game{
        private:    // Not required. All is private by default.
            Player p1;
            Player p2;
            // array<string, 52> shflDeck;
            string* shflDeck;
            Card deck;
            vector<string> turns;
            int pointerdeck; 
            int drawAmount;

        public:
            // methods defined inline:
            Player getp1();
            Player getp2();

            std::string to_string();

            // // Constructors:
            Game();

            // ~Game();
            
            Game(Player& pl1, Player& pl2);

            // string strCard(string tplyer);

            void playTurn();

            int printLastTurn();

            void playAll();

            int printWiner();

            int printLog();

            int printStats();

    };
}