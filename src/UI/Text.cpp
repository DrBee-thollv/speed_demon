#include "UI/Text.hpp"
#include <iostream>

Text::Text()
{}


Text::Text(std::string text, int size)
{
    setup_text_field(text, size);
}


Text::Text(std::string text, int size, sf::Vector2f position)
{
    setup_text_field(text, size);
    m_text.setPosition(position);
}


void Text::setup_text_field(std::string text, int size)
{
    if (!m_font.loadFromFile("P:\\sfml_assets\\fast99.ttf"))
    {
        std::cout << "Error Loading font.\n";
    }

    m_text.setFont(m_font);
    m_text.setString(text);
    m_text.setCharacterSize(size);
    sf::FloatRect text_rect = m_text.getLocalBounds();
    m_text.setOrigin(text_rect.left + text_rect.width / 2.0f, text_rect.top  + text_rect.height / 2.0f);
}


Text::Text(const Text& copy)
    :
    m_text(copy.get_sf_text()),
    m_font(copy.get_font())
{
}


Text& Text::operator=(const Text& rhs)
{
    this->m_text = rhs.get_sf_text();
    this->m_font = rhs.get_font();
    return *this;
}


void Text::set_position(sf::Vector2f position)
{
    m_text.setPosition(position);
}


void Text::set_string(std::string text)
{
    m_text.setString(text);
}


const sf::Text Text::get_sf_text() const
{
    return m_text;
}

const sf::Font Text::get_font() const
{
    return m_font;
}

const sf::FloatRect Text::get_bounds() const
{
    return m_text.getLocalBounds();
}
