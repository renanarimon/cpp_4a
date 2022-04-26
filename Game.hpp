# pragma once
# include <iostream>
#include <queue>
#include "Player.hpp"
namespace coup{
    class Game
        {
        private:
            std::queue<Player> player_queue;
        public:
            Game();
            ~Game();
            void turn() const;
            std::vector<std::string> players() const;
            std::string winner() const;
        };
}


