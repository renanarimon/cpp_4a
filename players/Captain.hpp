# pragma once
#include"Player.hpp"

namespace coup{
    class Captain : public Player
    {
    private:
        /* data */
    public:
        Captain(Game game, std::string name);
        ~Captain();
        void steal(Player p); //steal 2 coins
        void block(Player p); //block another captain from steal
    };
}


