#pragma once
#include <iostream>
#include "Game.hpp"

namespace coup
{
    class Game;
    class Player
    {

    public:
        /*Actions allow in the game*/
        enum Action
        {
            income_A,
            foreign_aid_A,
            coup_A,
            block_A,
            tax_A,
            transfer_A,
            steal_A,
            couped_A
        };
        static const int SEVEN = 7;
        static const int TEN = 10;

    protected:
        Game *_game;
        std::string _name;
        std::string _role;
        int _coins;
        Action _lastAction; // last action this player did
        Player *_onPlayer;  // The player on whom the last action was performed
        bool _alive;        // true iff player is alive

    public:
        Player(Game &game, std::string name);   // constuctor
        ~Player();                              // distructor
        void income();                          // +1 coin
        void foreign_aid();                     // +2 coins -> can be blocked
        virtual void coup(Player &p);           // coup player p from game -> -7 coins
        std::string role() const;               // this player role
        int coins() const;                      // num of coins
        void startTurn(Action action);             // check exceptions before each turn
        void endTurn(Action action, Player &p); // move turn to next player, save details of this turn
        void setCoins(int num, char a_l);


        //get & set
        std::string getName()
        {
            return this->_name;
        }
        Action getLastAction()
        {
            return this->_lastAction;
        }
        void setLastAction(Action newAction)
        {
            this->_lastAction = newAction;
        }

        void setOnPlayer(Player &p)
        {
            this->_onPlayer = &p;
        }

        void setAlive(bool alive)
        {
            this->_alive = alive;
        }

        bool isAlive()
        {
            return this->_alive;
        }
        Player *getOnPlayer()
        {
            return this->_onPlayer;
        }
    };

}