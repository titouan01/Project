/*
** EPITECH PROJECT, 2021
** Display SFMLL
** File description:
** header file
*/

#ifndef DISPSFML_H_
#define DISPSFML_H_

#include <iostream>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "../../monitorCore/IMonitorDisplay.hpp"
#include "../../monitorCore/IMonitorModule.hpp"
#include "../../modules/CpuPourcent.hpp"

class MonitorDisplaySfml : public IMonitorDisplay {
    public:
        MonitorDisplaySfml(sf::VideoMode vm = sf::VideoMode(1920, 1080), std::string window_name = "MyGKrellM_Graphical");
        ~MonitorDisplaySfml();
        void displayModules(void);
        void window_loop(void);
        void switch_modules(sf::Event);
        void disp_legend(void);
        void disp_bg(void);
        void refreshModules(void);
        void convert_network(void);
        void disp_hostname(sf::RenderWindow &window, IMonitorModule *module);
        void disp_systeminfo(sf::RenderWindow &window, IMonitorModule *module);
        void disp_datetime(sf::RenderWindow &window, IMonitorModule *module);
        void disp_memory(sf::RenderWindow &window, IMonitorModule *module);
        void disp_cpu(sf::RenderWindow &window, IMonitorModule *module);
        void disp_network(sf::RenderWindow &window, IMonitorModule *module);
        void disp_memorydisk(sf::RenderWindow &window, IMonitorModule *module);
        void disp_uptime(sf::RenderWindow &window, IMonitorModule *module);
        void disp_task(sf::RenderWindow &window, IMonitorModule *module);
        void disp_sensors(sf::RenderWindow &window, IMonitorModule *module);
        void run(void);

    protected:
    private:
        sf::RenderWindow _window;
        float _network_up;
        float _network_down;
        CpuPourcent *_cpu_pourcent;
        sf::Clock _clock;
        std::vector<IMonitorModule *> _modules;
        std::vector<void (MonitorDisplaySfml::*)(sf::RenderWindow &, IMonitorModule *)> _disp_mod_ptr;
};

#endif /* !DISPSFML_H_ */