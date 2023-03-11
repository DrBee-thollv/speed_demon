#pragma once
#include <SFML/Graphics.hpp>
class Enemy
{
public:
	Enemy();


	sf::RectangleShape get_enemy_position();
	

	void move(float elapsedTime, float dt, float player_impact);


	void spawn();


	void reset();

private:
	sf::RectangleShape m_shape = sf::RectangleShape(sf::Vector2f(10.0f,20.0f));
	
	bool m_moving = 0;
};

