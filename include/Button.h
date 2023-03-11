#pragma once
#include <SFML/Graphics.hpp>

class Button : public sf::Drawable
{
public:
	Button();


	Button(sf::Text text, sf::Vector2f size, sf::Vector2f position);


	Button& operator=(Button other);


	bool is_clicked(sf::Vector2f mouse_position);


	void draw(sf::RenderTarget& target, sf::RenderStates states) const
{
		// You can draw other high-level objects
		target.draw(m_shape);
		target.draw(m_button_text);
}


	sf::RectangleShape get_button_shape() const;


	sf::Text get_button_text() const;
	
private:
	sf::RectangleShape m_shape;
	sf::Text m_button_text;
};

