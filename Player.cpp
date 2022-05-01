# include "Player.hpp"
#include<exception>

namespace coup{
    
    Player::Player(Game &game, std::string name){
        this->_game = &game;
        this->_name = name; 
        this->_role = "player"; 
        this->_coins = 0;
        this->_alive = true;
        this->_game->_players.push_back(this); //add player to game
        this->_game->_size++;
        this->_lastAction = Action::block_A;
        this->_onPlayer = this;
        this->_onPlayer2 = this;

    }

    Player::~Player(){}

    void Player::income(){
        this->myTurn();
        this->_coins++;
        this->endTurn(Action::income_A, *this);
    }

    void Player::foreign_aid(){
        this->myTurn();
        this->_coins += 2;
        this->endTurn(Action::foreign_aid_A, *this);
    }
    void Player::coup(Player &p){
    }
    std::string Player::role() const{
        return this->_role;
    }
    int Player::coins() const{
        return this->_coins;
    }

    void Player::setCoins(int num, char a_l){
        if(a_l == '+'){this->_coins += num;}
        else if(a_l == '-'){this->_coins -= num;}
        else{
            throw std::invalid_argument("a_l must be + or -");
        }
    }

    /*check if it's my turn.
        if true - play*/
    void Player::myTurn(){
        if(!this->_alive){
            throw std::logic_error("this player is not alive");
        }
        if(this->_game->turn() != this->_name){
            throw std::logic_error("this is not your'e turn!");
        }
        Action a = this->_lastAction;
        switch (a)
        {
        case Action::foreign_aid_A:
            this->setCoins(2, '+');
            break;
        // case Action::tax_A:
        //     this->setCoins(3, '+');
        //     break;
        case Action::coup_A:
            this->_alive = false;
            break;
        case Action::steal_A:
            if(this->_onPlayer->coins()>=2){
                this->setCoins(2, '+');
                this->_onPlayer->setCoins(2, '-');
            }
            else if(this->_onPlayer->coins() == 1){
                this->setCoins(1, '+');
                this->_onPlayer->setCoins(1, '-');
            }
            break;

        case Action::transfer_A:
            if(this->_onPlayer->coins() >=1){
                this->_onPlayer->setCoins(1, '-');
                this->_onPlayer2->setCoins(1, '+');
            }
            break;
            // }else{
            //     throw std::range_error("can't take coin from player with no coins");
            // }

        default:
            break;
        }

    }
    void Player::endTurn(Action action, Player& p){
        if (this->_game->_currTurn == this->_game->_size-1){
            this->_game->_currTurn = 0;
        }
        else{this->_game->_currTurn++;}
        this->setLastAction(action);
        this->setOnPlayer(p);

    }
}