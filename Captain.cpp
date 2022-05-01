# include "Captain.hpp"

namespace coup{
    Captain::Captain(Game &game, std::string name) :
    Player(game, std::move(name)) {
        this->_role = "Captain";
    }

    Captain::~Captain(){}

    /*stael
    cost: ---
    goal: stael 2 coins from another player
    block: allowed by Ambassador OR capitan*/
    void Captain::steal(Player &p){
        this->startTurn(Action::steal_A);
        if(p.isAlive() && p.coins()>=2){
            p.setCoins(2, '-');
            this->setCoins(2, '+');
        }
        this->endTurn(Action::steal_A, p);
        
    } 

    /*block another captain from steal*/
    void Captain::block(Player &p){
        if(p.role() == "Capitan" && p.getLastAction() == Action::steal_A){
            p.setLastAction(Action::block_A);
        }else{
            throw std::logic_error("can block only Capitan that stoled last turn");
        }
    } 
}