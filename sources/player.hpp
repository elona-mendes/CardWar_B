#include <iostream>
#include <stdexcept>
#include <vector>
#include "card.hpp"

// // some_header_file.h
#ifndef Player_H
#define Player_H

using namespace std;

namespace ariel {
    class Player{
        private:    // Not required. All is private by default.
            string name;
            int stksize;
            // string deck[26]; 
            string* deck = new string[26];
            int winPoints;

        public:
            // methods defined inline:
            string getName();
            std::string to_string();

            void setstksize(int n){
                stksize = n;
            }
            void setwinPoints(int p){
                winPoints = winPoints+p;
            }
            string* getDeck(){
                return deck;
            }
            void setDeck(string* dck){
                deck = dck;
            }
            // // Constructors:
            Player() ;
            //{
            //     std::cout << "Player()" << std::endl; 
            //     name = "None";
            //     stksize = 26;
            //     tken = 0;
            //     sumpoint = 0;
            //     crd = 1;
            // }
            Player(string n) ;
            // { 
            //     std::cout << "Player(string)" << std::endl; 
            //     name =  n; 
            //     stksize = 26;
            //     tken = 0;
            //     sumpoint = 0;
            //     // crd = Card();
            // }
            // ~Player();

            int stacksize();

            int cardesTaken();
    };
}

// // your code
#endif