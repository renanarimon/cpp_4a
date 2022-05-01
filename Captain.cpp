# include "Captain.hpp"

namespace coup{
    Captain::Captain(Game &game, std::string name) :
    Player(game, name) {
        this->_role = "Captain";
    }

    Captain::~Captain(){}

    /*steal 2 coins*/
    void Captain::steal(Player &p){
        this->endTurn(Action::steal_A, p);
        
    } 

    /*block another captain from steal*/
    void Captain::block(Player &p){
        if(p.role().compare("Capitan") && p.getLastAction() == Action::steal_A){
            p.setLastAction(Action::block_A);
        }else{
            throw std::logic_error("can block only Capitan that stoled last turn");
        }
    } 
}