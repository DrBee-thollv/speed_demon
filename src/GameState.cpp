#include "GameState.hpp"
#include <iostream>
#include "UI/Button.hpp"

HomeScreen::HomeScreen(GameInstance* game)
{
    this->m_game_instance = game;

    this->m_title_text = std::make_unique<Text>("SPEED\nDEMON", 100, 
                                                sf::Vector2f(game->m_game_window.getSize().x / 2,
                                                             game->m_game_window.getSize().y / 3));

    this->m_play_button = std::make_unique<Button>("Play", 65, 
                                                   sf::Vector2f((game->m_game_window.getSize().x / 2.0) - 200,
                                                                 game->m_game_window.getSize().y / 2.0));

    this->m_exit_button = std::make_unique<Button>("Exit", 65,
                                                   sf::Vector2f((game->m_game_window.getSize().x / 2.0) + 200,
                                                                 game->m_game_window.getSize().y / 2.0));
}

void HomeScreen::process_events()
{
    sf::Event event;
    while (this->m_game_instance->m_game_window.pollEvent(event))
    {
        if (event.type == sf::Event::MouseButtonReleased)
        {
            if (m_play_button->is_clicked(this->m_game_instance->m_game_window.mapPixelToCoords(sf::Mouse::getPosition(this->m_game_instance->m_game_window))))
            {
                this->m_game_instance->m_next_state = new MainGameLoop(this->m_game_instance);
            }
            if (m_exit_button->is_clicked(this->m_game_instance->m_game_window.mapPixelToCoords(sf::Mouse::getPosition(this->m_game_instance->m_game_window))))
            {
                this->m_game_instance->m_game_window.close();
            }
        }
    }
}

void HomeScreen::update(sf::Time dt)
{
}

void HomeScreen::draw()
{
    this->m_game_instance->m_game_window.draw(*m_play_button);
    this->m_game_instance->m_game_window.draw(*m_title_text);
    this->m_game_instance->m_game_window.draw(*m_exit_button);
}


GameOver::GameOver(GameInstance* game)
{
    this->m_game_instance = game;

    this->m_game_over_text = std::make_unique<Text>("GAME OVER", 100, 
                                                          sf::Vector2f(game->m_game_window.getSize().x / 2, 
                                                                       game->m_game_window.getSize().y / 3));

    this->m_play_again_button = std::make_unique<Button>("Play Again", 65,
                                                         sf::Vector2f((game->m_game_window.getSize().x / 2.0) - 400, 
                                                                      game->m_game_window.getSize().y / 2.0));

    this->m_exit_button = std::make_unique<Button>("Exit", 65, 
                                                   sf::Vector2f((game->m_game_window.getSize().x / 2.0) + 400, 
                                                                game->m_game_window.getSize().y / 2.0));
}

void GameOver::process_events()
{   
    sf::Event event;
    while (this->m_game_instance->m_game_window.pollEvent(event))
    {
        if (event.type == sf::Event::MouseButtonReleased)
        {
            if (m_play_again_button->is_clicked(this->m_game_instance->m_game_window.mapPixelToCoords(sf::Mouse::getPosition(this->m_game_instance->m_game_window))))
            {
                this->m_game_instance->m_next_state = new MainGameLoop(this->m_game_instance);
            }
            if (m_exit_button->is_clicked(this->m_game_instance->m_game_window.mapPixelToCoords(sf::Mouse::getPosition(this->m_game_instance->m_game_window))))
            {
                this->m_game_instance->m_game_window.close();
            }
        }
    }
}

void GameOver::update(sf::Time dt)
{
}

void GameOver::draw()
{
    this->m_game_instance->m_game_window.draw(*m_play_again_button);
    this->m_game_instance->m_game_window.draw(*m_game_over_text);
    this->m_game_instance->m_game_window.draw(*m_exit_button);
}


MainGameLoop::MainGameLoop(GameInstance* game)
    :
    m_player(Player()),
    m_enemies{Enemy(), Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy()}
{
    this->m_game_instance = game;

    m_score = std::make_unique<Text>("0", 25, sf::Vector2f(game->m_game_window.getSize().x / 2.0, 25));

    m_elapsed_time.restart();
}

void MainGameLoop::process_events()
{
    sf::Event event;
    while (this->m_game_instance->m_game_window.pollEvent(event))
    {
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Button::Left)
                m_player.set_grow();
            else if (event.mouseButton.button == sf::Mouse::Button::Right)
                m_player.set_shrink();
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            if (event.mouseButton.button == sf::Mouse::Button::Left)
                m_player.set_grow();
            else if (event.mouseButton.button == sf::Mouse::Button::Right)
                m_player.set_shrink();
        }
    }
}

void MainGameLoop::update(sf::Time dt)
{
    for (int idx = 0; idx < 10; idx++)
    {
        m_enemies[idx].spawn();
        m_enemies[idx].move(m_elapsed_time.getElapsedTime().asSeconds(), dt.asSeconds(), m_player.get_player_size_percentage());
        auto enemy_global_position = m_enemies[idx].get_enemy_position().getGlobalBounds();
        if (enemy_global_position.left < 0)
        {
            m_enemies[idx].reset();
        }
        if (enemy_global_position.intersects(m_player.get_player_position().getGlobalBounds()))
        {
            this->m_game_instance->m_next_state = new GameOver(this->m_game_instance);
        }
    }
    
    m_player_position = m_player.get_player_position();
    m_score->set_string(std::to_string((int)std::floor(m_elapsed_time.getElapsedTime().asSeconds())));
}

void MainGameLoop::draw()
{
    this->m_game_instance->m_game_window.draw(*m_score);
    this->m_game_instance->m_game_window.draw(m_player_position);
    for (int idx = 0; idx < 15; idx++)
    {
        this->m_game_instance->m_game_window.draw(m_enemies[idx].get_enemy_position());
    }
}
