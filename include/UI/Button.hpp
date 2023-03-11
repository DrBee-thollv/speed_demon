#pragma once

#include <SFML/Graphics.hpp>
#include "UI/Text.hpp"

class Button : public sf::Drawable
{
public:
	Button();


	Button(SD_Text text, sf::Vector2f position);


	Button(std::string text, int text_size, sf::Vector2f position);


	Button& operator=(Button other);


	bool is_clicked(sf::Vector2f mouse_position);


	void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// You can draw other high-level objects
		target.draw(m_shape);
		target.draw(m_button_text);
	}


	sf::RectangleShape get_button_shape() const;


	SD_Text get_button_text() const;
	
private:
	sf::RectangleShape m_shape;
	SD_Text m_button_text;
};

