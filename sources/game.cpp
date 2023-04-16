#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <string>
#include "game.hpp"

using namespace std;
using namespace ariel;      
            

// Constructors:
Game::Game(Player& pl1, Player& pl2) : p1(pl1), p2(pl2){
    this->p1 = pl1; 
    this->p2 = pl2;
    this->p1.setstksize(26);
    this->p2.setstksize(26);
    
    this->drawAmount = 0;
    this->pointerdeck = 0;
    this->shflDeck = deck.deckShuffling();

    int p1Index = 0, p2Index = 0;
    int idx = 0;
    for (auto i : this->shflDeck){
        if (idx % 2 == 0) {
            this->p1.setDeck(i, p1Index);
            p1Index = p1Index + 1;
        } else {
            this->p2.setDeck(i, p2Index);
            p2Index = p2Index + 1;
        }
        idx += 1;
    }
}

string strCard(string tplyer){
    //check valus
    string number = tplyer.substr(0, tplyer.length() - 1);
    //check symbols
    char symbol = tplyer.back();
    string symbolcmplt;
    //Turns the symbol representer into the complete symbol name.
    if (symbol == 'H'){
        symbolcmplt = "Hearts";
    }
    else if (symbol == 'D'){
        symbolcmplt = "Diamonds";
    }
    else if (symbol == 'C'){
        symbolcmplt = "Clubs";
    }
    else if (symbol == 'S'){
        symbolcmplt = "Spades";
    }
    else{
        throw std::runtime_error("Error: Symbol error.");
    }
    string cardVal;
    //Turns the number representer into the symbol name.
    if (number.length()>1){
        if (number.compare("10") == 0){
            cardVal = number;
        }
        if (number.compare("11") == 0){
            cardVal = "Jack";
        }
        if (number.compare("12") == 0){
            cardVal = "Queen";
        }
        if (number.compare("13") == 0){
            cardVal = "King";
        }
        if (number.compare("14") == 0){
            cardVal = "As";
        }
    }
    else{
        cardVal = number;
    }
    string card = cardVal + " of " + symbolcmplt;
    return card;
}

int Game::printLastTurn(){
    // Accessing last element
    int s = this->turns.size();
    if(s < 1){
        throw std::runtime_error("Error: Unable to print the last turn.");
    }
    std::cout << this->turns.back() << endl;
    return 0;
}

void Game::playTurn(){
    //Check if the players are the same one.
    if(&p1 == &p2){
        throw std::runtime_error("Error: Player cannot play with himself.");
    }
    if(this->p1.stacksize()<=0 || this->p2.stacksize()<=0){
        throw std::runtime_error("Error: It is not possible to play if there are no cards in the deck.");
    }
    string totalTurn = ""; 
    int winflag = 0;
    int totalPoints = 0;

    while (winflag == 0 && this->p1.stacksize()>0){

        //plus two points for each card
        totalPoints = totalPoints+2;

        string card1 = this->p1.getDeck()[this->pointerdeck];
        string card2 = this->p2.getDeck()[this->pointerdeck];

        totalTurn = totalTurn + this->p1.getName() + " Played " + strCard(card1) + " " + this->p2.getName() + " Played " + strCard(card2) + ".";
        //check valus
        int val1 = std::stoi(card1.substr(0, card1.length() - 1));
        int val2 = std::stoi(card2.substr(0, card2.length() - 1));

        this->pointerdeck = pointerdeck+1;
        this->p1.setstksize(this->p1.stacksize()-1);
        this->p2.setstksize(this->p2.stacksize()-1);

        if(val2 == 14 && val1 == 2){
           this->p1.setwinPoints(totalPoints);
            totalTurn = totalTurn + " " + this->p1.getName() + " wins.";
            winflag = 1; 
        }
        else if(val1 == 14 && val2 == 2){
            this->p2.setwinPoints(totalPoints);
            totalTurn = totalTurn + " " + this->p2.getName() + " wins.";
            winflag = 1;
        }
        else if((val1 > val2) || (val2 == 14 && val1 == 2)){
            this->p1.setwinPoints(totalPoints);
            totalTurn = totalTurn + " " + this->p1.getName() + " wins.";
            winflag = 1;
        }
        else if(val1 < val2 || (val1 == 14 && val2 == 2)){
            this->p2.setwinPoints(totalPoints);
            totalTurn = totalTurn + " " + this->p2.getName() + " wins.";
            winflag = 1;
        }
        //Draw
        else{
            this->drawAmount = this->drawAmount+1;
            if(this->p1.stacksize()>0){
                this->pointerdeck = pointerdeck+1;
                this->p1.setstksize(this->p1.stacksize()-1);
                this->p2.setstksize(this->p2.stacksize()-1);
                totalTurn = totalTurn + " Draw. ";
                totalPoints = totalPoints+2;
            }
            else{
                totalTurn = totalTurn + " Draw. end of the game. ";
            }
        }   
    }

    //If we stopped the turn because we ran out of cards, give each player the points of his cards back
    if(winflag == 0){
        this->p1.setwinPoints(totalPoints/2);
        this->p2.setwinPoints(totalPoints/2);
    }
    //add the turn to the vector
    this->turns.push_back(totalTurn);
}

void Game::playAll(){
    while(this->p1.stacksize()>0 && this->p2.stacksize()>0){
        playTurn();
    }
}

int Game::printWiner(){
    if((this->p1.cardesTaken() + this->p2.cardesTaken()) == 0){
        throw std::runtime_error("Error: It is not possible to declare a winner before the start of the game.");
    }
    else if(this->p1.cardesTaken() > this->p2.cardesTaken()){
        std::cout<<this->p1.getName() << " win the game!"<<endl;
    }
    else if(this->p1.cardesTaken() < this->p2.cardesTaken()){
        std::cout<<this->p2.getName()<< " win the game!" <<endl;
    }
    else{
        std::cout<<"Draw"<<endl;
    }
    return 0;
}

int Game::printLog(){
    for (const std::string& s : this->turns) {
        std::cout << s << std::endl;
    }
    return 0;
}

int Game::printStats(){
    // for each player prints basic statistics: win rate, cards won, <other stats you want to print>.
    // Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
    double cardPlayed = 26 - this->p1.stacksize();

    double p1cardsWon = this->p1.cardesTaken()/2;
    double p1winRate = (p1cardsWon/cardPlayed) * 100; 
    
    double p2cardsWon = this->p2.cardesTaken()/2;
    double p2winRate = (p2cardsWon/cardPlayed) * 100; 

    double drawRate = (this->drawAmount/cardPlayed) * 100;

    std::cout<< this->p1.getName() <<" statistics: " << endl;
    std::cout<< "Win rate: " << p1winRate << "%,  Cards won (The number of cards he took from the other player): " << p1cardsWon << endl;

    std::cout<< this->p2.getName() <<" statistics: " << endl;
    std::cout<< "Win rate: " << p2winRate << "%,  Cards won (The number of cards he took from the other player): " << p2cardsWon << endl;

    std::cout<< "General statistic: " << endl;
    std::cout<< "Draw rate: " << drawRate << ",  Amount of draws that happand: " << this->drawAmount << endl;
    return 0;
}
