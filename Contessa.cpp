#include "Contessa.hpp"

namespace coup
{
    Contessa::Contessa(Game &game, std::string name) : Player(game, std::move(name))
    {
        this->_role = "Contessa";
    }
    Contessa::~Contessa() {}

    /*goal: block Assassin from coup -> return couped player to game*/
    void Contessa::block(Player &p)
    {
        if(!p.isAlive() || !this->isAlive()){
            throw std::logic_error("player p is not alive");
        }
        
        if (p.role() == "Assassin" && p.getLastAction() == Action::coup3_A)
        {
            this->_game->_size++; 
            p.getOnPlayer()->setAlive(true); // return couped player to game
            p.setLastAction(Action::block_A); // block p
        }
        else
        {
            throw std::logic_error("can block only Assassin that couped last turn");
        }
    }

}