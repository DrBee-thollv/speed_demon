#include "Player.h"

Player::Player()
{
	m_shape.setOrigin(m_shape.getSize().x / 2, m_shape.getSize().y / 2);
}

sf::RectangleShape Player::get_player_position()
{
	m_shape.setPosition((sf::Vector2f)sf::Mouse::getPosition());
	return m_shape;
}
