#include "Contessa.hpp"

namespace coup{
    Contessa::Contessa(Game &game, std::string name) :
    Player(game, std::move(name)){
        this->_role = "Contessa";
    }
    Contessa::~Contessa(){}

    /*block Assassin from coup*/
    void Contessa::block(Player &p){
        std::cout << "in block\n"; 
        std::cout << this->role() << std::endl; 
        if(p.role() == "Assassin" && p.getLastAction() == Action::coup_A){
            std::cout << "in if\n"; 
            this->_game->_size++;
            p.getOnPlayer()->setAlive(true);
            p.setLastAction(Action::block_A); 
        }else{
            std::cout << "in else\n"; 
            throw std::logic_error("can block only Assassin that couped last turn");
        }
    } 

}