# pragma once
# include "Player.hpp"

namespace coup{
    class Assassin : public Player
    {
    private:
        /* data */
    public:
        Assassin(Game game, std::string name);
        ~Assassin();
        virtual void coup(Player p) override; //coup with 3 coins
    };

    
}