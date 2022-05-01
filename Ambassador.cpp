#include "Ambassador.hpp"

namespace coup
{
    Ambassador::Ambassador(Game &game, std::string name) : Player(game, std::move(name))
    {
        this->_role = "Ambassador";
    }
    Ambassador::~Ambassador() {}

    /*transfer
    cost: ---
    goal: transfer 1 coin from p1 to p2
    block: NOT allowed*/
    void Ambassador::transfer(Player &from, Player &to)
    {
        this->startTurn(Action::transfer_A);
        if (from.isAlive() && to.isAlive() && from.coins() > 0)
        {
            from.setCoins(1, '-');
            to.setCoins(1, '+');
            this->endTurn(Action::transfer_A, from);
        }
    }

    /*block captain from steal*/
    void Ambassador::block(Player &p)
    { 
        if (p.role() == "Captain" && p.getLastAction() == Action::steal_A)
        {
            p.setLastAction(Action::block_A);
            p.setOnPlayer(p);
        }
    }
}