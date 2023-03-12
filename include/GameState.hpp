#pragma once

#include <SFML/Graphics.hpp>
#include "UI/Button.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "GameInstance.hpp"

class GameState
{
public:
	/*
	 * @brief Each GameState object will require a process_events function implementation to handle user inputs.
	*/
	virtual void process_events() = 0;


	/*
	 * @brief Each GameState object will require an update function implementation to handle entity updating.
	 *
	 * @param sf::Time the time difference between the update should be the FPS period.
	*/
	virtual void update(sf::Time dt) = 0;


	/*
	 * @brief Each GameState object will require a draw function implementation to handle drawing the scene.
	*/
	virtual void draw() = 0;

protected:
	/*@brief There is a single game instance that needs to be shared with the GameState object so 
			 they can interact with the game window!
	*/
	GameInstance* m_game_instance;
};


class HomeScreen : public GameState
{
public:
	/*
	 * @brief This handles the inital home screen, and lets the player either play or quit the game.
	 */
	HomeScreen(GameInstance* game);


	/*
	 * @brief Process the events for the homescreen. There are two avenues, switching gamestates to the MainGameLoop
	 *        or exiting the game and closing the window.
	 */
	void process_events();


	/*
	 * @brief Empty implementation since all buttons/text are static.
	 *
	 * @param sf::Time the time difference between the update should be the FPS period.
	 */
	void update(sf::Time dt);


	/*
	 * @brief Draw the two buttons and main game title text.
	 */
	void draw();

private:
	std::unique_ptr<Text> m_title_text; /*@brief Speed Demon tittle text object.*/

	std::unique_ptr<Button> m_play_button; /*@brief Play speed demon button.*/

	std::unique_ptr<Button> m_exit_button; /*@brief Exit game button.*/
};


class GameOver : public GameState
{
public:
	/*
	 * @brief Screams game over at the user, allowing them to play again or exit the game.
	 */
	GameOver(GameInstance* game);


	/*
	 * @brief Process the events for the game over screen. There are two avenues, switching
	 *        gamestates to the MainGameLoop or exiting the game and closing the window.
	 */
	void process_events();


	/*
	 * @brief Empty implementation since all buttons/text are static.
	 *
	 * @param sf::Time the time difference between the update should be the FPS period.
	 */
	void update(sf::Time dt);

	/*
	 * @brief Draw the two buttons and game over text.
	 */
	void draw();

private:
	std::unique_ptr<Text> m_game_over_text; /*@brief Game Over text object.*/

	std::unique_ptr<Button> m_play_again_button; /*@brief Play Again button.*/

	std::unique_ptr<Button> m_exit_button; /*@brief Exit game button.*/
};


class MainGameLoop : public GameState
{
public:
	/*
	 * @brief Plays the actual speed demon game, initializes enemies, player, and score.
	 */
	MainGameLoop(GameInstance* game);


	/*
	 * @brief Handles checking for player growing or shrinking inputs.
	 */
	void process_events();


	/*
	 * @brief Checks for collisions between the enemies and the player, updates player location and score.
	 *        If collision occurs sets next state to GameOver state.
	 */
	void update(sf::Time dt);


	/*
	 * @brief Draws all enemies, the player, and the players score.
	 */
	void draw();

private:
	std::unique_ptr<Text> m_score; /*@brief Players current score as a text object.*/

	Enemy m_enemies[15]; /*@brief An array of enemy objects, at most 15 enemies on screen.*/

	Player m_player; /*@brief The players object.*/

	sf::Clock m_elapsed_time; /*@brief Keeps track of elapsed time since game started for their score.*/

	sf::RectangleShape m_player_position; /*@brief Players position to draw.*/
};
