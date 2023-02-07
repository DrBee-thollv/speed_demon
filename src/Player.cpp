#include "Player.h"

Player::Player()
{
	m_shape.setOrigin(m_shape.getSize().x / 2, m_shape.getSize().y / 2);
	m_grow_player = false;
	m_shrink_player = false;
}

void Player::set_grow()
{
	m_grow_player = !m_grow_player;
}

void Player::set_shrink()
{
	m_shrink_player = !m_shrink_player;
}

sf::RectangleShape Player::get_player_position()
{
	if(m_grow_player && !m_shrink_player)
		m_shape.setSize(sf::Vector2f(m_shape.getSize().x * 1.001, m_shape.getSize().y * 1.001));
	else if(!m_grow_player && m_shrink_player)
		m_shape.setSize(sf::Vector2f(m_shape.getSize().x * 0.999, m_shape.getSize().y * 0.999));

	m_shape.setPosition((sf::Vector2f)sf::Mouse::getPosition());

	return m_shape;
}
