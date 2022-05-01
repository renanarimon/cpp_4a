# include "Ambassador.hpp"

namespace coup{
    Ambassador::Ambassador(Game &game, std::string name) :
    Player(game, name) {
        this->_role = "Ambassador";
    }
    Ambassador::~Ambassador(){}

    /*transfer 1 coin from p1 to p2*/
    void Ambassador::transfer(Player &from, Player &to){
        this->_onPlayer2 = &to;
        this->endTurn(Action::transfer_A, from);
        
    }
    void Ambassador::block(Player &p){ // block steal
        if(p.role().compare("Captain") == 0 && p.getLastAction() == Action::steal_A){
            p.setLastAction(Action::block_A);
            p.setOnPlayer(p);
        }
    } 
}