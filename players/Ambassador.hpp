# pragma once
# include "Player.hpp"

namespace coup{
    class Ambassador : public Player
    {
    private:
        /* data */
    public:
        Ambassador(Game game, std::string name);
        ~Ambassador();
        void transfer(Player from, Player to);
        void block(Player p); // block steal
    };

    
}