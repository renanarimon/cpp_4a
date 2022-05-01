# include "Assassin.hpp"
#include <algorithm>

namespace coup{
    Assassin::Assassin(Game &game, std::string name) :
    Player(game, std::move(name)) {
        this->_role = "Assassin";
    }

    Assassin::~Assassin(){}

    void Assassin::coup(Player &p){
        this->myTurn(Action::coup_A);
        if(this->coins()>= SEVEN && p.isAlive()){
            this->setCoins(SEVEN, '-');
            p.setAlive(false);
            this->_game->_size--;
            this->endTurn(Action::coup_A, *this);
        }
        else if(this->coins() >= 3 && p.isAlive()){
            this->setCoins(3, '-');
            p.setAlive(false);
            p.setLastAction(Action::couped_A); // can be blocked
            this->_game->_size--;
            this->endTurn(Action::coup_A, p);
        }else{
            throw std::logic_error("can't coup with less than 3 coins");
        }
               
    }
}