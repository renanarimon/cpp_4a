#include "Game.hpp"
#include <exception>
namespace coup
{

    /*constructor*/
    Game::Game()
    {
        std::vector<Player *> p;
        this->_players = p;
        this->_currTurn = 0;
        this->_size = 0;
        this->_started = false;
    }

    /*distructor*/
    Game::~Game() {}

    /*return the name of the player whose turn to play now*/
    std::string Game::turn() const
    {
        if (this->_size <= 0)
        {
            throw std::out_of_range("no players in game");
        }
        return this->_players[this->_currTurn]->getName();
    }

    /*Returns the names of the players currently active in the game*/
    std::vector<std::string> Game::players() const
    {
        if (this->_size <= 0)
        {
            throw std::out_of_range("no players in game");
        }
        std::vector<std::string> names;
        for (Player *p : this->_players)
        {
            if (p->isAlive()) // player in the game iff he is alive
            {
                names.push_back(p->getName());
            }
        }
        return names;
    }

    /*return the winner iff there is only one player left*/
    std::string Game::winner() const
    {
        if (this->_started && this->_size == 1)
        {
            for (Player *p : this->_players)
            {
                if (p->isAlive())
                {
                    return p->getName();
                }
            }
        }
        throw std::out_of_range("there is no winner");
    }

}
