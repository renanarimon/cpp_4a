#include "Duke.hpp"
#include "string.h"

namespace coup{
    Duke::Duke(Game &game, std::string name) :
    Player(game, name){
        this->_role = "Duke";
    }
    Duke::~Duke(){}

    void Duke::tax(){
        this->myTurn();
        this->_coins += 3;
        this->endTurn(Action::tax_A, *this);
    }
    /*block foreign_aid*/
    void Duke::block(Player &p){ 
        if(p.getLastAction() == Action::foreign_aid_A){
            p.setLastAction(Action::block_A);
        }
    } 

}