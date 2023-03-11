#include "UI/Text.hpp"
#include <iostream>

SD_Text::SD_Text()
{}


SD_Text::SD_Text(std::string text, int size)
{
    setup_text_field(text, size);
}


SD_Text::SD_Text(std::string text, int size, sf::Vector2f position)
{
    setup_text_field(text, size);
    m_text.setPosition(position);
}


void SD_Text::setup_text_field(std::string text, int size)
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


SD_Text::SD_Text(const SD_Text& copy)
    :
    m_text(copy.get_sf_text()),
    m_font(copy.get_font())
{
}


SD_Text& SD_Text::operator=(const SD_Text& rhs)
{
    this->m_text = rhs.get_sf_text();
    this->m_font = rhs.get_font();
    return *this;
}


void SD_Text::set_position(sf::Vector2f position)
{
    m_text.setPosition(position);
}


void SD_Text::set_string(std::string text)
{
    m_text.setString(text);
}


const sf::Text SD_Text::get_sf_text() const
{
    return m_text;
}

const sf::Font SD_Text::get_font() const
{
    return m_font;
}

const sf::FloatRect SD_Text::get_bounds() const
{
    return m_text.getLocalBounds();
}
