# pragma once
# include "Player.hpp"

namespace coup{
    class Duke : public Player
    {
    private:
        /* data */
    public:
        Duke(Game &game, std::string name);
        ~Duke();
        void tax();
        void block(Player &p); //block foreign_aid
    };
}