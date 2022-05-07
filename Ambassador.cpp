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
        if (!from.isAlive() || !to.isAlive())
        {
            throw std::logic_error("player from/to is not alive");
        }
        this->startTurn(Action::transfer_A);
        if (from.coins() > 0)
        {
            from.setCoins(1, '-');
            to.setCoins(1, '+');
            this->endTurn(Action::transfer_A, from);
        }
        else
        {
            throw std::logic_error("not enought coins to steal");
        }
    }

    /*block captain from steal*/
    void Ambassador::block(Player &p)
    {
        if (!p.isAlive() || !this->isAlive())
        {
            throw std::logic_error("player p is not alive");
        }
        if (p.role() != "Captain")
        {
            throw std::logic_error("can block only Captain");
        }
        if (p.getLastAction() == Action::steal1_A)
        {
            p.getOnPlayer()->setCoins(1, '+');
            p.setCoins(1, '-');
        }
        else if (p.getLastAction() == Action::steal2_A)
        {
            p.getOnPlayer()->setCoins(2, '+');
            p.setCoins(2, '-');
        }
        else if(p.getLastAction() != Action::steal2_A){
            throw std::logic_error("captain didn't steal");
        }
    }

}