#include <iostream>
#include <stdexcept>
#include <vector>
#include "card.hpp"

#ifndef Player_H
#define Player_H

using namespace std;

namespace ariel {
    class Player{
        private:  
            string name;
            int stksize;
            static const int DECK_SIZE = 26;
            string* deck = new string[DECK_SIZE];
            int winPoints;

        public:
            string getName();

            string* getDeck();

            void setstksize(int n);

            void setwinPoints(int p);

            void setDeck(string& value, int index);

            // Constructors:
            Player() ;

            Player(string n) ;

            int stacksize();

            int cardesTaken();
    };
}

#endif