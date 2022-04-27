# pragma once
# include <iostream>
#include <deque>
#include <vector>
namespace coup{
    class Game
        {
        
            
        public:
            std::vector<std::string> _players;
            size_t _currTurn;
            size_t _size;
            Game();
            ~Game();
            std::string turn() const;
            std::vector<std::string> players() const;
            std::string winner() const;
            void addPlayer(std::string name);
        };
}


