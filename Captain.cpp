#include "Captain.hpp"

namespace coup
{
    Captain::Captain(Game &game, std::string name) : Player(game, std::move(name))
    {
        this->_role = "Captain";
    }

    Captain::~Captain() {}

    /*stael
    cost: ---
    goal: stael 2 coins from another player
    block: allowed by Ambassador OR capitan*/
    void Captain::steal(Player &p)
    {
        this->startTurn(Action::steal1_A);
        if (!p.isAlive())
        {
            throw std::logic_error("player p is not alive");
        }
        if (p.coins() >= 2)
        {
            p.setCoins(2, '-');
            this->setCoins(2, '+');
            this->endTurn(Action::steal2_A, p);
        }
        else if (p.coins() == 1)
        {
            p.setCoins(1, '-');
            this->setCoins(1, '+');
            this->endTurn(Action::steal1_A, p);
        }
        else
        {
            this->endTurn(Action::steal0_A, p);
        }
    }

    /*block another captain from steal*/
    void Captain::block(Player &p)
    {
        if (!p.isAlive() || !this->isAlive())
        {
            throw std::logic_error("player p is not alive");
        }
        if (p.role() != "Captain")
        {
            throw std::logic_error("can block only Capitan");
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
    }
}