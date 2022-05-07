#include "Player.hpp"
#include <exception>

namespace coup
{
    /*constructor*/
    Player::Player(Game &game, std::string name)
    {
        if(game._size >0 && game.players().size() >= SIX){
            throw std::logic_error("this game is full");
        }
        if(game._started){
            throw std::logic_error("game has started!");
        }
        this->_game = &game;
        this->_name = std::move(name);
        this->_role = "player";
        this->_coins = 0;
        this->_alive = true;
        this->_game->_players.push_back(this); // add player to game
        this->_game->_size++;
        this->_lastAction = Action::block_A;
        this->_onPlayer = this;
    }

    /*distructor*/
    Player::~Player() {}

    /*income
     cost: ---
     goal: get 1 coin
     block: NOT allowed*/
    void Player::income()
    {
        this->startTurn(Action::income_A);
        this->_coins++;
        this->endTurn(Action::income_A, *this);
    }
    /*foreign_aid
    cost: ---
    goal: get 2 coins
    block: allowed*/
    void Player::foreign_aid()
    {
        this->startTurn(Action::foreign_aid_A);
        this->setCoins(2, '+');
        this->endTurn(Action::foreign_aid_A, *this);
    }
    /*coup player p from game
    cost: 7 coins
    goal: dissmiss player from game
    block: NOT allowed*/
    void Player::coup(Player &p)
    {
        this->startTurn(Action::coup_A);
        if(this->coins() < SEVEN){
            throw std::logic_error(this->getName()+" do not have 7 coins to coup");
        }
        if(!p.isAlive()){
            throw std::logic_error("player p is not alive");
        }
        p.setAlive(false);
        this->_game->_size--;
        this->setCoins(SEVEN, '-');
        this->endTurn(Action::coup_A, p);
    }

    std::string Player::role() const
    {
        return this->_role;
    }
    int Player::coins() const
    {
        // if (!this->_alive)
        // {
        //     throw std::logic_error("this player is out of game");
        // }
        return this->_coins;
    }
    /*'+': increase coins
      '-': decrease*/
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

    /*check exceptions before each turn*/
    void Player::startTurn(Action action)
    {
        if (!this->_alive)
        {
            throw std::logic_error("this player is not alive");
        }

        if (this->_game->turn() != this->_name)
        {
            throw std::logic_error("this is not your'e turn!");
        }

        if (this->coins() >= TEN && action != Action::coup_A)
        {
            throw std::logic_error("you have at least 10 coins, have to coup!");
        }
        if(this->_game->players().size() < 2 || this->_game->players().size() >SIX){
            throw std::logic_error("game must consist 2-6 players");
        }
        this->_game->_started = true;
    }

    /*move turn to next player, save details of this turn*/
    void Player::endTurn(Action action, Player &p)
    {
        if (this->_game->_currTurn == this->_game->_players.size() - 1)
        {

            this->_game->_currTurn = 0;
        }
        else
        {
            this->_game->_currTurn++;
        }
        while (!this->_game->_players[this->_game->_currTurn]->isAlive()) // skip not-alive players
        {
            if (this->_game->_currTurn == this->_game->_players.size() - 1)
            {
                this->_game->_currTurn = 0;
            }
            else
            {
                this->_game->_currTurn++;
            }
        }
        this->setLastAction(action);
        this->setOnPlayer(p);
    }
}