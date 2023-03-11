#pragma once
#include <SFML/Graphics.hpp>

class Text : public sf::Drawable
{
public:
    Text();


    Text(std::string text, int size);


    Text(std::string text, int size, sf::Vector2f position);


    Text(const Text& copy);


    Text& operator=(const Text& rhs);


    void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// You can draw other high-level objects
		target.draw(m_text);
	}


    void set_position(sf::Vector2f position);


    void set_string(std::string text);


    const sf::Text get_sf_text() const;


    const sf::Font get_font() const;


    const sf::FloatRect get_bounds() const;


private:
    void setup_text_field(std::string text, int size);

    sf::Font m_font;
    sf::Text m_text;
};