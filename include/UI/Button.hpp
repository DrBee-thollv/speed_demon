#pragma once

#include <SFML/Graphics.hpp>
#include "UI/Text.hpp"

class Button : public sf::Drawable
{
public:
	/*
	 * @brief Default constructor for a button.
	 */
	Button();


	/*
	 * @brief Create a button with pre-existing Text object and a specific position.
	 *
	 * @param Text Contains the wording within the button.
	 * @param sf::Vector2f Position of the button.
	 */
	Button(Text text, sf::Vector2f position);


	/*
	 * @brief Create a button by providing wording, the size of the wording, and the position. 
	 		  The button will auto-adjust size according to the text size.
	 *
	 * @param std::string Wording in the button.
	 * @param int Size of wording.
	 * @param sf::Vector2f Position of button.
	 */
	Button(std::string text, int text_size, sf::Vector2f position);


	/*
	 * @brief Generates buttons size from text within, then resets origin to the middle of the 
	 		  button, and relocates them to position specified.
	 *
	 * @param sf::Vector2f Position of button.
	 */
	void setup_button(sf::Vector2f position);


	/*
	 * @brief Equality operator overload for easy assignment.
	 *
	 * @param Button Object to assign from.
	 */
	Button& operator=(Button other);


	/*
	 * @brief Performs a boolean check to see if button was pressed by user.
	 *
	 * @param sf::Vector2f Position of mouse during release point.
	 * 
	 * @returns bool Returns whether mouse action is within button bounds.
	 */
	bool is_clicked(sf::Vector2f mouse_position);


	/*
	 * @brief Since Button class inherits from sf::Drawable, the draw function must be 
	 		  implemented. A simple rectangle is drawn with text over top. 
	 *
	 * @param sf::RenderTarget Target where the entities will be drawn to.
	 * @param sf::RenderStates Not sure what this is for, not implemented.
	 */
	void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_shape);
		target.draw(m_button_text);
	}


	/*
	 * @brief Getter for button box.
	 *
	 * @returns sf::RectangleShape Buttons rectangle background.
	 */
	sf::RectangleShape get_button_shape() const;


	/*
	 * @brief Getter for text within button.
	 *
	 * @returns Text Object holding the buttons text information.
	 */
	Text get_button_text() const;
	
private:
	sf::RectangleShape m_shape; /*@brief Shape of the buttons background.*/

	Text m_button_text; /*@brief Text for the buttons context.*/
};

