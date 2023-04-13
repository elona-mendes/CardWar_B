#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include "player.hpp"

using namespace std;
using namespace ariel; 

// some_header_file.h
// #ifndef player.h
// #define player.h


string Player::getName() { return this->name;  }

// // Coinstructors:
Player::Player() {
    // std::cout << "Player()" << std::endl; 
    this->name = "None";
    this->stksize = 0;
    this->winPoints = 0;
}
Player::Player(string n) { 
    // std::cout << "Player(string)" << std::endl; 
    this->name =  n; 
    this->stksize = 0;
    this->winPoints = 0;
}

int Player::stacksize(){
    return this->stksize;
}

int Player::cardesTaken(){
    return this->winPoints;
}

// your code
// #endif