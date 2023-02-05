#include "Enemy.h"

Enemy::Enemy()
{
	m_shape.setPosition(sf::Vector2f(1920, std::rand() % 1080));
}

sf::RectangleShape Enemy::get_enemy_position()
{
	return m_shape;
}

void Enemy::move(float elapsedTime, float dt)
{
	if (m_moving) m_shape.move(-(elapsedTime / 0.01) * dt, 0);
}

void Enemy::spawn()
{
	if (!m_moving)
	{
		int spawn_trigger = std::rand() % 100;
		if (spawn_trigger==1) m_moving = true;
	}
}

void Enemy::reset()
{
	m_shape.setPosition(sf::Vector2f(1920, std::rand() % 1080));
	m_moving = false;
}
