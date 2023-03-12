#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	/*
	 * @brief Default constructor for the player.
	 */
	Player();


	/*
	 * @brief Grows or shrinks the player and updates the position according to the mouse position.
	 * 
	 * @returns bool Returns players shape to be drawn to screen.
	 */
	sf::RectangleShape get_player_position();


	/*
	 * @brief Toggle the growing flag.
	 */
	void set_grow();


	/*
	 * @brief Toggle the shrinking flag.
	 */
	void set_shrink();


	/*
	 * @brief Calculates the players size as a percentage where the default size is 100%.
	 * 
	 * @returns float player size as a percentage.
	 */
	const float get_player_size_percentage() const;

private:
	/*@brief Sets the players shape as a recatngle with default size.*/
	sf::RectangleShape m_shape = sf::RectangleShape(sf::Vector2f(50.0f, 100.0f));

	/*@brief Grow player flag.*/
	bool m_grow_player;

	/*@brief Shrink player flag.*/
	bool m_shrink_player;
};

