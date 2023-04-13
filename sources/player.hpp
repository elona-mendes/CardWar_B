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
        private:  
            string name;
            int stksize;
            // string deck[26]; 
            string* deck = new string[26];
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
            // ~Player(){
            //     return;
            // }

            int stacksize();

            int cardesTaken();
    };
}

// // your code
#endif