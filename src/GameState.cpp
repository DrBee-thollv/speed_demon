#include "GameState.h"
#include <iostream>
#include "Button.h"

HomeScreen::HomeScreen(GameInstance* game)
{
    this->m_game_instance = game;

    if (!game_font.loadFromFile("P:\\sfml_assets\\fast99.ttf"))
    {
        std::cout << "Error Loading font.\n";
    }
    m_title_text.setFont(game_font);
    m_title_text.setString("SPEED DEMON");
    m_title_text.setCharacterSize(50);
    m_title_text.setPosition(sf::Vector2f((game->m_game_window.getSize().x / 3), (game->m_game_window.getSize().y / 3)));

    sf::Text play_text("Play", game_font);
    this->play_button = Button(play_text,
                               sf::Vector2f(game->m_game_window.getSize().x / 10, game->m_game_window.getSize().x / 20),
                               sf::Vector2f((game->m_game_window.getSize().x / 2.0) - 200, (game->m_game_window.getSize().y / 2.0)));

    sf::Text exit_text("Exit", game_font);
    this->exit_button = Button(exit_text,
                               sf::Vector2f(game->m_game_window.getSize().x / 10, game->m_game_window.getSize().x / 20),
                               sf::Vector2f((game->m_game_window.getSize().x / 2.0) + 200, (game->m_game_window.getSize().y / 2.0)));
}

void HomeScreen::process_events()
{
    sf::Event event;
    while (this->m_game_instance->m_game_window.pollEvent(event))
    {
        if (event.type == sf::Event::MouseButtonReleased)
        {
            if (play_button.is_clicked(this->m_game_instance->m_game_window.mapPixelToCoords(sf::Mouse::getPosition(this->m_game_instance->m_game_window))))
            {
                this->m_game_instance->m_next_state = new MainGameLoop(this->m_game_instance);
            }
            if (exit_button.is_clicked(this->m_game_instance->m_game_window.mapPixelToCoords(sf::Mouse::getPosition(this->m_game_instance->m_game_window))))
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
    this->m_game_instance->m_game_window.draw(play_button);
    this->m_game_instance->m_game_window.draw(m_title_text);
    this->m_game_instance->m_game_window.draw(exit_button);
}


GameOver::GameOver(GameInstance* game)
{
    this->m_game_instance = game;

    if (!game_font.loadFromFile("P:\\sfml_assets\\fast99.ttf"))
    {
        std::cout << "Error Loading font.\n";
    }
    game_over_text.setFont(game_font);
    game_over_text.setString("GAME OVER");
    game_over_text.setPosition(sf::Vector2f((game->m_game_window.getSize().x / 2.0), (game->m_game_window.getSize().y / 2.0)));

    sf::Text play_again_text("Play Again", game_font);
    this->play_again_button = Button(play_again_text,
                                     sf::Vector2f(game->m_game_window.getSize().x / 10, game->m_game_window.getSize().x / 20),
                                     sf::Vector2f((game->m_game_window.getSize().x / 2.0) - 400, (game->m_game_window.getSize().y / 2.0) - 200));

    sf::Text exit_text("Exit", game_font);
    this->exit_button = Button(exit_text, 
                               sf::Vector2f(game->m_game_window.getSize().x / 10, game->m_game_window.getSize().x / 20),
                               sf::Vector2f((game->m_game_window.getSize().x / 2.0) + 400, (game->m_game_window.getSize().y / 2.0) - 200));
}

void GameOver::process_events()
{   
    sf::Event event;
    while (this->m_game_instance->m_game_window.pollEvent(event))
    {
        if (event.type == sf::Event::MouseButtonReleased)
        {
            if (play_again_button.is_clicked(this->m_game_instance->m_game_window.mapPixelToCoords(sf::Mouse::getPosition(this->m_game_instance->m_game_window))))
            {
                this->m_game_instance->m_next_state = new MainGameLoop(this->m_game_instance);
            }
            if (exit_button.is_clicked(this->m_game_instance->m_game_window.mapPixelToCoords(sf::Mouse::getPosition(this->m_game_instance->m_game_window))))
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
    this->m_game_instance->m_game_window.draw(play_again_button);
    this->m_game_instance->m_game_window.draw(game_over_text);
    this->m_game_instance->m_game_window.draw(exit_button);
}


MainGameLoop::MainGameLoop(GameInstance* game)
    :
    player(Player()),
    enemies{Enemy(), Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy() ,Enemy()}
{
    this->m_game_instance = game;

    if (!score_font.loadFromFile("P:\\sfml_assets\\fast99.ttf"))
    {
        std::cout << "Error Loading font.\n";
    }
    score.setFont(score_font);
    score.setCharacterSize(25);
    score.setPosition(sf::Vector2f(game->m_game_window.getSize().x / 2.0, 0));
    score.setString("0");

    elapsedTime.restart();
}

void MainGameLoop::process_events()
{
    
}

void MainGameLoop::update(sf::Time dt)
{
    for (int idx = 0; idx < 10; idx++)
    {
        enemies[idx].spawn();
        enemies[idx].move(elapsedTime.getElapsedTime().asSeconds(), dt.asSeconds());
        auto enemy_global_position = enemies[idx].get_enemy_position().getGlobalBounds();
        if (enemy_global_position.left < 0)
        {
            enemies[idx].reset();
        }
        if (enemy_global_position.intersects(player.get_player_position().getGlobalBounds()))
        {
            this->m_game_instance->m_next_state = new GameOver(this->m_game_instance);
        }
    }
    
    m_player_position = player.get_player_position();
    score.setString(std::to_string((int)std::floor(elapsedTime.getElapsedTime().asSeconds())));
}

void MainGameLoop::draw()
{
    this->m_game_instance->m_game_window.draw(score);
    this->m_game_instance->m_game_window.draw(m_player_position);
    for (int idx = 0; idx < 15; idx++)
    {
        this->m_game_instance->m_game_window.draw(enemies[idx].get_enemy_position());
    }
}
