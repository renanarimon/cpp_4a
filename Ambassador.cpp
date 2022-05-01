#include "Ambassador.hpp"

namespace coup
{
    Ambassador::Ambassador(Game &game, std::string name) : Player(game, std::move(name))
    {
        this->_role = "Ambassador";
    }
    Ambassador::~Ambassador() {}

    /*transfer 1 coin from p1 to p2*/
    void Ambassador::transfer(Player &from, Player &to)
    {
        this->myTurn(Action::transfer_A);
        if (from.getAlive() && to.getAlive() && from.coins() > 0)
        {
            from.setCoins(1, '-');
            to.setCoins(1, '+');
            this->_onPlayer2 = &to;
            this->endTurn(Action::transfer_A, from);
        }
    }
    
    // block steal
    void Ambassador::block(Player &p)
    { 
        if (p.role() == "Captain" && p.getLastAction() == Action::steal_A)
        {
            p.setLastAction(Action::block_A);
            p.setOnPlayer(p);
        }
    }
}