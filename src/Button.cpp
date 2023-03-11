#include "Button.h"
Button::Button()
{
}

Button::Button(sf::Text text, sf::Vector2f size, sf::Vector2f position)
	:
	m_shape(size),
	m_button_text(text)
{
	m_shape.setPosition(position);
	m_shape.setFillColor(sf::Color::Red);
	m_button_text.setCharacterSize(size.y / 2);
	m_button_text.setPosition(position);
}

Button& Button::operator=(Button other)
{
	m_shape = other.get_button_shape();
	m_button_text = other.get_button_text();

	return *this;
}


bool Button::is_clicked(sf::Vector2f mouse_position)
{
	return (m_shape.getGlobalBounds().contains(mouse_position)) ? true : false;
}


sf::RectangleShape Button::get_button_shape() const
{
	return m_shape;
}


sf::Text Button::get_button_text() const
{
	return m_button_text;
}
