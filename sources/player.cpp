#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include "player.hpp"

using namespace std;
using namespace ariel; 

string Player::getName() { return this->name;  }

// // Coinstructors:
Player::Player() {
    this->name = "None";
    this->stksize = 0;
    this->winPoints = 0;
}
Player::Player(string n) { 
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