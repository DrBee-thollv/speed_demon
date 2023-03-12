#pragma once
#include <SFML/Graphics.hpp>

class GameState;

class GameInstance
{
public:
	/*
	 * @brief Initial constructor that generates the game window and inital state of the game.
	 */
	GameInstance();


	/*
	 * @brief Execute the game loop of event handling and rendering the frames.
	 */
	void run_game();


	/*
	 * @brief Gets the mouse position relative to the game window.
	 */
	sf::Vector2f get_mouse_position();
	

	/*@brief Holds the next game state if necessary, and will take current_state the next iteration.*/
	GameState* m_next_state;

	/*@brief Holds the current game state, and will handle events and render based on this game state.*/
	GameState* m_current_state;

	/*@brief The game window object, this is where entities get rendered to. Main game screen.*/
	sf::RenderWindow m_game_window;

private:
	/*@brief Used to handle the frame timing so entities get drawn at a set time interval.*/
	sf::Clock m_frame_clock;
	
	/*@brief Game runs at a static 60fps.*/
	const sf::Time m_time_per_frame = sf::seconds(1.0f / 60.0f);
};

