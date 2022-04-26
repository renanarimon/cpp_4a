#include "Game.hpp"
#include <exception>
namespace coup{
    Game::Game(){}
    Game::~Game(){}

    /*Print the name of the player whose turn to play now*/
    void Game::turn() const{
        std::cout << this->player_queue.front().getName() << std::endl;
    }

    /*Returns the names of the players currently active in the game*/
    std::vector<std::string> Game::players() const{
        return {this->player_queue.begin(), this->player_queue.end()};
    }

    /*return the winner iff there is only one player left*/
    std::string Game::winner() const{
        if(this->size == 1){
            return this->player_queue.front().getName();
        }
        else if (this->size <1)
        {
            throw std::out_of_range("game has no players");
        }
        else{
            throw std::invalid_argument("there is more than 1 player");
        }
        
    }
}