# pragma once
#include <iostream>
#include "Game.hpp"

namespace coup{
    class Player
    {
    protected:
        Game _game;
        std::string _name;
        std::string _role;
        int _coins;
    public:
        Player(Game game, std::string name, std::string role);
        ~Player();
        void income();
        void foreign_aid();
        virtual void coup(Player p);
        std::string role() const;
        int coins() const;

        std::string getName() const;
    };

    
}