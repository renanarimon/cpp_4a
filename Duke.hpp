# pragma once
# include "Player.hpp"

namespace coup{
    class Duke : public Player
    {
    public:
        Duke(Game &game, std::string name);
        ~Duke();
        void tax(); // +3 coins
        static void block(Player &p); //block foreign_aid
    };
}