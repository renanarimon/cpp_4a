#include "Player.hpp"
#include <exception>

namespace coup
{

    Player::Player(Game &game, std::string name)
    {
        this->_game = &game;
        this->_name = std::move(name);
        this->_role = "player";
        this->_coins = 0;
        this->_alive = true;
        this->_game->_players.push_back(this); // add player to game
        this->_game->_size++;
        this->_lastAction = Action::block_A;
        this->_onPlayer = this;
        this->_onPlayer2 = this;
    }

    Player::~Player() {}

    void Player::income()
    {
        this->myTurn(Action::income_A);
        this->_coins++;
        this->endTurn(Action::income_A, *this);
    }

    void Player::foreign_aid()
    {
        this->myTurn(Action::foreign_aid_A);
        this->_coins += 2;
        this->endTurn(Action::foreign_aid_A, *this);
    }
    void Player::coup(Player &p)
    {
        this->myTurn(Action::coup_A);
        p.setAlive(false);
        this->_game->_size--;
        this->endTurn(Action::coup_A, p);
    }
    std::string Player::role() const
    {
        return this->_role;
    }
    int Player::coins() const
    {
        return this->_coins;
    }

    void Player::setCoins(int num, char a_l)
    {
        if (a_l == '+')
        {
            this->_coins += num;
        }
        else if (a_l == '-')
        {
            this->_coins -= num;
        }
        else
        {
            throw std::invalid_argument("a_l must be + or -");
        }
    }

    /*check if it's my turn.
        if true - play*/
    void Player::myTurn(Action action)
    {
        if (!this->_alive)
        {
            throw std::logic_error("this player is not alive");
        }
        if (this->_game->turn() != this->_name)
        {
            throw std::logic_error("this is not your'e turn!");
        }

        if(this->coins()>=TEN && action!=Action::coup_A){
            throw std::logic_error("you have at least 10 coins, have to coup!");
        }

    }


    void Player::endTurn(Action action, Player &p)
    {
        if (this->_game->_currTurn == this->_game->_size - 1)
        {
            this->_game->_currTurn = 0;
        }
        else
        {
            this->_game->_currTurn++;
        }
        while (!this->_game->_players[this->_game->_currTurn]->getAlive()) // skip not-alive players
        {
            this->_game->_currTurn++;
        }
        this->setLastAction(action);
        this->setOnPlayer(p);
    }
}