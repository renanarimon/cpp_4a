# pragma once
#include <iostream>
#include "Game.hpp"

namespace coup{
    class Game;
    class Player
    {
    public:
        enum Action{income_A, foreign_aid_A, coup_A, block_A, tax_A, transfer_A, steal_A, couped_A};
    protected:
        Game* _game;
        std::string _name;
        std::string _role;
        int _coins;
        // bool foreign_this_round;
        Action _lastAction;
        Player* _onPlayer;
        Player* _onPlayer2;
        bool _alive;
    public:
        
        Player(Game &game, std::string name);
        ~Player();
        void income();
        void foreign_aid();
        virtual void coup(Player &p);
        std::string role() const;
        int coins() const;
        void myTurn();
        void endTurn(Action action, Player& p);
        void setCoins(int num, char a_l);

        std::string getName(){
            return this->_name;
        }
        Action getLastAction(){
            return this->_lastAction;
        }
        void setLastAction(Action newAction){
            this->_lastAction = newAction;
        }
        bool isAlive() const{
            return _alive;
        }
        void setOnPlayer(Player& p){
            this->_onPlayer = &p;
        }

        void setAlive(bool alive){
            this->_alive = alive;
        }
 
    };

    
}