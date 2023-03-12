#include "GameInstance.hpp"
#include "GameState.hpp"

GameInstance::GameInstance()
{
	m_game_window.create(sf::VideoMode(1920, 1080), "SFML works!");
	m_next_state = nullptr;
	this->m_current_state = new HomeScreen(this); // Initial state is homescreen.
}

void GameInstance::run_game()
{
	m_frame_clock.restart();
	sf::Time time_since_last_update = sf::Time::Zero;
	while (m_game_window.isOpen())
	{
		// Restart function restarts the clock as well as returning time passed since last restart.
		time_since_last_update += m_frame_clock.restart();

		// Once last update time is greater then our 60FPS thershold, update it until it gets below that threshold.
		while (time_since_last_update > m_time_per_frame)
		{
			time_since_last_update -= m_time_per_frame;
			m_current_state->process_events();
			m_current_state->update(m_time_per_frame);
		}

		m_game_window.clear();
		m_current_state->draw();
		m_game_window.display();

		if (m_next_state != nullptr) // If next state is populated switch to it.
			m_current_state = m_next_state;
		
	}
}

sf::Vector2f GameInstance::get_mouse_position()
{
	return m_game_window.mapPixelToCoords(sf::Mouse::getPosition(this->m_game_window));
}
