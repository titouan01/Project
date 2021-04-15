/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush3-louis.boulet
** File description:
** main
*/

#include "RoueLibre.hpp"

void displayHelp(void)
{
    std::cout << "MyGKrellm" << std::endl;
    std::cout << "-----" << std::endl << std::endl;
    std::cout << "./MyGKrellm -g : Launch GKrellm in graphic mode" << std::endl;
    std::cout << "./MyGKrellm -n : Launch GKrellm in ncurses mode" << std::endl;
    std::cout << "./MyGKrellm -h : Display help" << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 1) {
        std::cerr << "No arguments found. Please launch ./MyGKrellm -h" << std::endl;
        return (84);
    }
    if (av[1][0] == '-') {
        if (av[1][1] == 'h') {
            displayHelp();
            return (0);
        }
        if (av[1][1] == 'g') {
            MonitorDisplaySfml start;
            start.window_loop();
        } else if (av[1][1] == 'n') {
            ncurse start;
            start.run();
        } else {
            std::cerr << "Invalid argument. Please launch ./MyGKrellm -h for help" << std::endl;
            return (84);
        }
        return (0);
    }
    std::cerr << "Invalid argument. Please launch ./MyGKrellm -h for help" << std::endl;
    return (84);
}