#include "GameInstance.hpp"
#include "GameState.hpp"

GameInstance::GameInstance()
{
	m_game_window.create(sf::VideoMode(1920, 1080), "SFML works!");
	m_next_state = nullptr;
	this->m_current_state = new HomeScreen(this);
}

void GameInstance::run_game()
{
	m_frame_clock.restart();
	sf::Time time_since_last_update = sf::Time::Zero;
	while (m_game_window.isOpen())
	{
		time_since_last_update += m_frame_clock.restart();

		while (time_since_last_update > m_time_per_frame)
		{
			time_since_last_update -= m_time_per_frame;
			m_current_state->process_events();
			m_current_state->update(m_time_per_frame);
		}

		m_game_window.clear();
		m_current_state->draw();
		m_game_window.display();

		if (m_next_state != nullptr)
		{
			m_current_state = m_next_state;
		}
	}
}

