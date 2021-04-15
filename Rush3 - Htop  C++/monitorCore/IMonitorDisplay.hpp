/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

class IMonitorDisplay {
    public:

        virtual void displayModules(void) = 0;
        virtual void refreshModules(void) = 0;
        virtual void run(void) = 0;

    protected:
        /*
            Liste modules IMonitorModule = [GPU, RAM, GPU, Réseau, ...]

            Boucle si Imonitormodule[index].isActivated():
                SI CLASSE NCURSES:
                    Imonitormodule[index].displayNcurses();
                SINON
                    Imonitormodule[index].displaySfml();

        */
    private:
};

#endif /* !IMONITORDISPLAY_HPP_ */
