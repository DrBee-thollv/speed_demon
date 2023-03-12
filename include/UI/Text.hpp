#pragma once
#include <SFML/Graphics.hpp>

class Text : public sf::Drawable
{
public:
    /*
	 * @brief Default constructor for text ui.
	 */
    Text();


    /*
	 * @brief Constructor for text with size specified, used when buttons are created.
	 */
    Text(std::string text, int size);


    /*
	 * @brief Constructor for text with size and position specified, used for text only entities.
	 */
    Text(std::string text, int size, sf::Vector2f position);


    /*
	 * @brief Copy constructor.
	 */
    Text(const Text& copy);


    /*
	 * @brief Assignment operator.
	 */
    Text& operator=(const Text& rhs);


    /*
	 * @brief Since Text class inherits from sf::Drawable, the draw function must be 
	 		  implemented. Text will be displayed to the target.
	 */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// You can draw other high-level objects
		target.draw(m_text);
	}


    /*
	 * @brief Setter for position of text.
	 */
    void set_position(sf::Vector2f position);


    /*
	 * @brief Setter for text string.
	 */
    void set_string(std::string text);


    /*
	 * @brief Get the SFML Text object.
	 */
    const sf::Text get_sf_text() const;


    /*
	 * @brief Get SFML Font used by text.
	 */
    const sf::Font get_font() const;


    /*
	 * @brief Get the rectangle of the text boundary.
	 */
    const sf::FloatRect get_bounds() const;


private:
    /*
	 * @brief Resets origin to allow positioning of text easier and more straight forward.
	 */
    void setup_text_field(std::string text, int size);


    /*@brief SFML Font of the text.*/
    sf::Font m_font;

    /*@brief SFML Text object.*/
    sf::Text m_text;
};