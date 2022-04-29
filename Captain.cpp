# include "Captain.hpp"

namespace coup{
    Captain::Captain(Game &game, std::string name) :
    Player(game, name) {
        this->_role = "Captain";
    }

    Captain::~Captain(){}

    /*steal 2 coins*/
    void Captain::steal(Player &p){
        if(p.coins()>=2){
            this->_coins +=2;
            p.setCoins(2, '+');
        }
    } 

    /*block another captain from steal*/
    void Captain::block(Player &p){
        if(p.role().compare("Capitan") && p.getLastAction().compare("steal") == 0){
            p.setLastAction("blocked");
        }else{
            throw std::logic_error("can block only Capitan that stoled last turn");
        }
    } 
}