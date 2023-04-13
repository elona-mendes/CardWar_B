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

            void setstksize(int n){
                stksize = n;
            }
            void setwinPoints(int p){
                winPoints = winPoints+p;
            }
            string* getDeck(){
                return deck;
            }

            void setDeck(string& value, int index){
                deck[index] = value;
            }
            // Constructors:
            Player() ;

            Player(string n) ;

            int stacksize();

            int cardesTaken();
    };
}

#endif