#include "Duke.hpp"
#include "string.h"

namespace coup
{
    Duke::Duke(Game &game, std::string name) : Player(game, std::move(name))
    {
        this->_role = "Duke";
    }
    Duke::~Duke() {}

    /*tax 3 coins
    cost: ---
    goal: get 3 coins
    block: NOT allowed*/
    void Duke::tax()
    {
        this->startTurn(Action::tax_A);
        this->_coins += 3;
        this->endTurn(Action::tax_A, *this);
    }
    /*goal: block a player that made foreign_aid last turn*/
    void Duke::block(Player &p)
    {
        if (p.isAlive() && p.getLastAction() == Action::foreign_aid_A)
        { // only if last turn foreign_aid
            if (p.coins() >= 2)
            { // if p has 2 coins
                p.setCoins(2, '-');
            }
            else if (p.coins() == 1) // if p has 1 coin
            {
                p.setCoins(1, '-');
            }
            p.setLastAction(Action::block_A);
        }
        else
        { // p isn't alive OR lastAction isn't foreign_aid
            throw std::logic_error("can block only foreign_aid");
        }
    }

}