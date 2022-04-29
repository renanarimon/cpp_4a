# include "Ambassador.hpp"

namespace coup{
    Ambassador::Ambassador(Game &game, std::string name) :
    Player(game, name) {
        this->_role = "Ambassador";
    }
    Ambassador::~Ambassador(){}

    /*transfer 1 coin from p1 to p2*/
    void Ambassador::transfer(Player &from, Player &to){
        if(from.coins()>=1){
            from.setCoins(1, '-');
            to.setCoins(1, '+');
            this->endTurn(Action::transfer_A);
        }else{
            throw std::range_error("can't take coin from player with no coins");
        }
    }
    void Ambassador::block(Player &p){} // block steal
}