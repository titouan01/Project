/*
** EPITECH PROJECT, 2021
** disp objects
** File description:
** Header file
*/

#ifndef DISP_OBJ_H
#define DISP_OBJ_H

#include "DisplaySfml.hpp"

void disp_bg_rectangle(sf::RenderWindow &window, sf::RectangleShape &rectangle, sf::Vector2f size, sf::Color outline_color, sf::Color fill_color, float outline_thickness, sf::Vector2f pos);
void disp_rectangle(sf::RenderWindow &window, sf::RectangleShape &rectangle, sf::Vector2f size, sf::Color color, sf::Vector2f pos);
void disp_text(sf::RenderWindow &window, sf::Text &text, sf::Font font, sf::String string, unsigned int size, sf::Color color, sf::Uint32 style, sf::Vector2f pos);

#endif /* !DISP_OBJ_H */