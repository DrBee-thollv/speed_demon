#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();

	sf::RectangleShape get_player_position();

private:
	sf::RectangleShape m_shape = sf::RectangleShape(sf::Vector2f(50.0f, 100.0f));
};

