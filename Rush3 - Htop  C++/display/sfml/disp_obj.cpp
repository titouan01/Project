/*
** EPITECH PROJECT, 2021
** disp objects
** File description:
** file
*/

#include "disp_obj.hpp"

void disp_bg_rectangle(sf::RenderWindow &window, sf::RectangleShape &rectangle, sf::Vector2f size, sf::Color outline_color, sf::Color fill_color, float outline_thickness, sf::Vector2f pos)
{
    rectangle.setSize(size);
    rectangle.setOutlineColor(outline_color);
    rectangle.setFillColor(fill_color);
    rectangle.setOutlineThickness(outline_thickness);
    rectangle.setPosition(pos.x, pos.y);
    window.draw(rectangle);
}

void disp_rectangle(sf::RenderWindow &window, sf::RectangleShape &rectangle, sf::Vector2f size, sf::Color color, sf::Vector2f pos)
{
    rectangle.setSize(size);
    rectangle.setFillColor(color);
    rectangle.setPosition(pos.x, pos.y);
    window.draw(rectangle);
}

void disp_text(sf::RenderWindow &window, sf::Text &text, sf::Font font, sf::String string, unsigned int size, sf::Color color, sf::Uint32 style, sf::Vector2f pos)
{
    text.setFont(font);
    text.setString(string);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setStyle(style);
    text.setPosition(pos);
    window.draw(text);
}