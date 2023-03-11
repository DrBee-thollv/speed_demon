#include "UI/Button.hpp"

Button::Button()
{
}


Button::Button(SD_Text text, sf::Vector2f position)
	:
	m_button_text(text)
{
	m_button_text.set_position(position);
	sf::FloatRect text_rect = m_button_text.get_bounds();

	m_shape.setSize(sf::Vector2f(text_rect.getSize().x + 10, text_rect.getSize().y + 10));
	sf::FloatRect button_rect = m_shape.getLocalBounds();
	m_shape.setOrigin(button_rect.left + button_rect.width / 2.0f, button_rect.top  + button_rect.height / 2.0f);
	m_shape.setPosition(position);
	m_shape.setFillColor(sf::Color::Red);
}


Button::Button(std::string text, int text_size, sf::Vector2f position)
	:
	m_button_text(SD_Text(text, text_size))
{
	m_button_text.set_position(position);
	sf::FloatRect text_rect = m_button_text.get_bounds();

	m_shape.setSize(sf::Vector2f(text_rect.getSize().x + 10, text_rect.getSize().y + 10));
	sf::FloatRect button_rect = m_shape.getLocalBounds();
	m_shape.setOrigin(button_rect.left + button_rect.width / 2.0f, button_rect.top  + button_rect.height / 2.0f);
	m_shape.setPosition(position);
	m_shape.setFillColor(sf::Color::Red);
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


SD_Text Button::get_button_text() const
{
	return m_button_text;
}