#include "Player.h"
#include<string>

Player::Player(std::string name, const int position, const int order) : p_name(name), p_position(position), p_order(order) {}

std::string Player::name() { return p_name;}
int Player::position() { return p_position;}
int Player::order() { return p_order;}