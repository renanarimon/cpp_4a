# include "Player.hpp"

namespace coup{
    Player::Player(Game game, std::string name, std::string role) :
    _game(game), _name(name), _role(role), _coins(0) {}
}