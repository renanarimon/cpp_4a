#include "Contessa.hpp"

namespace coup{
    Contessa::Contessa(Game &game, std::string name) :
    Player(game, std::move(name)){
        this->_role = "Contessa";
    }
    Contessa::~Contessa(){}

    /*block Assassin from coup*/
    void Contessa::block(Player &p){
        if(p.role() == "Assassin" && p.getLastAction() == Action::coup_A){
            p.getOnPlayer()->setAlive(true);
            p.setLastAction(Action::block_A);
        }else{
            throw std::logic_error("can block only Assassin that couped last turn");
        }
    } 

}