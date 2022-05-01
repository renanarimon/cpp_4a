#include "Assassin.hpp"
#include <algorithm>

namespace coup
{
    Assassin::Assassin(Game &game, std::string name) : Player(game, std::move(name))
    {
        this->_role = "Assassin";
    }

    Assassin::~Assassin() {}

    /*coup player p from game
    cost: 7 coins OR 3 coins
    goal: dissmiss player from game
    block: allowed only for coup by 3 coins*/
    void Assassin::coup(Player &p)
    {
        this->startTurn(Action::coup_A);
        if (this->coins() >= SEVEN && p.isAlive()) // 7 coins -> coup without block
        {
            this->setCoins(SEVEN, '-');
            p.setAlive(false);
            this->_game->_size--;
            this->endTurn(Action::coup_A, *this);
        }
        else if (this->coins() >= 3 && p.isAlive()) // 3 coins -> can be blocked
        {
            this->setCoins(3, '-');
            p.setAlive(false);
            p.setLastAction(Action::couped_A);
            this->_game->_size--;
            this->endTurn(Action::coup_A, p);
        }
        else
        {
            throw std::logic_error("can't coup with less than 3 coins");
        }
    }
}