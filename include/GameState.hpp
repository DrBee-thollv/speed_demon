#pragma once
#include <SFML/Graphics.hpp>
#include "UI/Button.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "GameInstance.hpp"


class GameState
{
public:
	virtual void process_events() = 0;


	virtual void update(sf::Time dt) = 0;


	virtual void draw() = 0;

protected:
	GameInstance* m_game_instance;
};


class HomeScreen : public GameState
{
public:
	HomeScreen(GameInstance* game);


	void process_events();


	void update(sf::Time dt);


	void draw();

private:
	std::unique_ptr<Text> m_title_text;
	std::unique_ptr<Button> m_play_button;
	std::unique_ptr<Button> m_exit_button;
};


class GameOver : public GameState
{
public:
	GameOver(GameInstance* game);


	void process_events();


	void update(sf::Time dt);


	void draw();

private:
	std::unique_ptr<Text> m_game_over_text;
	std::unique_ptr<Button> m_play_again_button;
	std::unique_ptr<Button> m_exit_button;
};


class MainGameLoop : public GameState
{
public:
	MainGameLoop(GameInstance* game);


	void process_events();


	void update(sf::Time dt);


	void draw();

private:
	std::unique_ptr<Text> m_score;
	Enemy m_enemies[15];
	Player m_player;
	sf::Clock m_elapsed_time;
	sf::RectangleShape m_player_position;
};

