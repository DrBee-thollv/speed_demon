#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Enemy.h"
#include "Player.h"
#include "GameInstance.h"


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
	sf::Font game_font;
	sf::Text m_title_text;
	Button play_button;
	Button exit_button;
};

class GameOver : public GameState
{
public:
	GameOver(GameInstance* game);

	void process_events();
	void update(sf::Time dt);
	void draw();

private:
	sf::Font game_font;
	sf::Text game_over_text;
	Button play_again_button;
	Button exit_button;
};

class MainGameLoop : public GameState
{
public:
	MainGameLoop(GameInstance* game);

	void process_events();
	void update(sf::Time dt);
	void draw();

private:
	sf::Font score_font;
	sf::Text score;
	Enemy enemies[15];
	Player player;
	sf::Clock elapsedTime;
	sf::RectangleShape m_player_position;
};

