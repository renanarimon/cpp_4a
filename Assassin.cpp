# include "Assassin.hpp"
#include <algorithm>

namespace coup{
    Assassin::Assassin(Game &game, std::string name) :
    Player(game, name) {
        this->_role = "Assassin";
    }

    Assassin::~Assassin(){}

    void Assassin::coup(Player &p){
        if(this->coins()>=7 && p.isAlive()){
            p.setAlive(false);
            this->endTurn(Action::coup_A, *this);
        }
        else if(this->coins() >= 3 && p.isAlive()){
            p.setLastAction(Action::couped_A); // can be blocked
            this->endTurn(Action::coup_A, p);
        }else{
            throw std::logic_error("can't coup with less than 3 coins");
        }
               
    }
}