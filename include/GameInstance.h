#pragma once
#include <SFML/Graphics.hpp>

class GameState;

class GameInstance
{
public:
	GameInstance();


	void run_game();
	

	GameState* m_next_state;

	GameState* m_current_state;

	sf::RenderWindow m_game_window;

private:
	sf::Clock m_frame_clock;
	
	const sf::Time m_time_per_frame = sf::seconds(1.0f / 60.0f);
};

