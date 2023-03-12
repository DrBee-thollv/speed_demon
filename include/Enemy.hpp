#pragma once
#include <SFML/Graphics.hpp>
class Enemy
{
public:
	/*
	 * @brief Default constructor for an enemy entity. Sets the position to a random y location 
	 *        on the right side of the screen.
	 */
	Enemy();


	/*
	 * @brief Getter for enemy rectangle.
	 */
	sf::RectangleShape get_enemy_position();
	

	/*
	 * @brief If enemy is moving, move to the left depending on time passed since last frame and 
	 		  player size.
	 */
	void move(float elapsedTime, float dt, float player_impact);


	/*
	 * @brief To create a scatter affect with enemies spawning, call this each frame and if random 
	 		  number generator hits the number 1 set moving to true.
	 */
	void spawn();


	/*
	 * @brief Enemy reached the left side of the screen, reset it to the right side on a random 
	 		  y-location and set moving low.
	 */
	void reset();

private:
	/*@brief Sets the enemys shape as a recatngle with default size.*/
	sf::RectangleShape m_shape = sf::RectangleShape(sf::Vector2f(10.0f,20.0f));
	
	/*@brief Notifies the enemy is moving and active.*/
	bool m_moving = 0;
};

