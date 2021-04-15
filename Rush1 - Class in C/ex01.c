/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
** Exercice 01
*/

#include "new.h"
#include "player.h"

int main(void)
{
    Object *player = new (Player);

    delete (player);
    return (0);
}
