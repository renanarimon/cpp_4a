# pragma once
# include <iostream>
#include <deque>
#include <vector>
#include "Player.hpp"
namespace coup{
    class Game
        {
        private:
            std::deque<Player> player_queue;
            int size;
        public:
            Game();
            ~Game();
            void turn() const;
            std::vector<std::string> players() const;
            std::string winner() const;
            void addPlayer(Player p);
        };
}


