/*
** EPITECH PROJECT, 2021
** display sfml
** File description:
** file
*/

#include "../../modules/HostnameModule.hpp"
#include "../../modules/Datetime.hpp"
#include "../../modules/Systeminfo.hpp"
#include "../../modules/Memory.hpp"
#include "../../modules/CpuInfo.hpp"
#include "../../modules/Network.hpp"
#include "../../modules/FileSystem.hpp"
#include "../../modules/Uptime.hpp"
#include "../../modules/Task.hpp"
#include "../../modules/Sensors.hpp"
#include "DisplaySfml.hpp"
#include "disp_mod_func.hpp"

MonitorDisplaySfml::MonitorDisplaySfml(sf::VideoMode vm, std::string window_name)
    : _window(vm, window_name), _cpu_pourcent(new CpuPourcent)
{
    run();
}

MonitorDisplaySfml::~MonitorDisplaySfml()
{
    for (std::size_t i = 0; i < _modules.size(); i++)
        delete _modules[i];
}

void MonitorDisplaySfml::disp_bg()
{
    sf::Texture t;
    t.loadFromFile("display/sfml/assets/sprites/galaxy.jpg");
    sf::Sprite s(t);
    _window.draw(s);
}

void MonitorDisplaySfml::switch_modules(sf::Event event)
{
    if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
            case sf::Keyboard::H:
                _modules[HOSTNAME]->switchModule();
                break;
            case sf::Keyboard::S:
                _modules[OPERATING_SYSTEM]->switchModule();
                break;
            case sf::Keyboard::T:
                _modules[DATETIME]->switchModule();
                break;
            case sf::Keyboard::P:
                _modules[CPU]->switchModule();
                break;
            case sf::Keyboard::M:
                _modules[RAM]->switchModule();
                break;
            case sf::Keyboard::N:
                _modules[NETWORK]->switchModule();
                break;
            case sf::Keyboard::D:
                _modules[MEMORYDISK]->switchModule();
                break;
            case sf::Keyboard::U:
                _modules[UPTIME]->switchModule();
                break;
            case sf::Keyboard::J:
                _modules[TASK]->switchModule();
                break;
            case sf::Keyboard::O:
                _modules[SENSOR]->switchModule();
                break;
            default:
                break;
        }
    }
}

void MonitorDisplaySfml::convert_network()
{
    Network *module = dynamic_cast<Network *>(_modules[NETWORK]);
    if (_clock.getElapsedTime().asSeconds() >= 1) {
        _network_up = module->getUpNet();
        _network_down = module->getDownNet();
        _clock.restart();
        return;
    }
    module->setDownNetMb(module->getDownNet() - _network_down);
    module->setUpNetMb(module->getUpNet() - _network_up);
}

void MonitorDisplaySfml::window_loop(void)
{
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                _window.close();
            switch_modules(event);
        }
        _window.clear();
        disp_bg();
        refreshModules();
        convert_network();
        displayModules();
        disp_legend();
        _window.display();
    }
}

void MonitorDisplaySfml::displayModules(void)
{
    for (std::size_t i = 0; i < _modules.size(); i++) {
        if (_modules[i]->isActivated())
            (this->*_disp_mod_ptr[_modules[i]->getModuleType()])(_window, _modules[i]);
    }
}

void MonitorDisplaySfml::refreshModules(void)
{
    for (std::size_t i = 0; i < _modules.size(); i++)
        _modules[i]->refresh();
}

void MonitorDisplaySfml::run(void)
{
    HostnameModule *hm = new HostnameModule;
    SystemInfo *si = new SystemInfo;
    Datetime *dt = new Datetime;
    CpuInfo *cpu = new CpuInfo;
    Memory *mem = new Memory;
    Network *nw = new Network;
    FileSystem *md = new FileSystem;
    Uptime *ut = new Uptime;
    Task *ts = new Task;
    Sensors *ss = new Sensors;

    _modules.push_back(hm);
    _modules.push_back(si);
    _modules.push_back(dt);
    _modules.push_back(cpu);
    _modules.push_back(mem);
    _modules.push_back(nw);
    _modules.push_back(md);
    _modules.push_back(ut);
    _modules.push_back(ts);
    _modules.push_back(ss);
    _disp_mod_ptr.push_back(&MonitorDisplaySfml::disp_hostname);
    _disp_mod_ptr.push_back(&MonitorDisplaySfml::disp_systeminfo);
    _disp_mod_ptr.push_back(&MonitorDisplaySfml::disp_datetime);
    _disp_mod_ptr.push_back(&MonitorDisplaySfml::disp_cpu);
    _disp_mod_ptr.push_back(&MonitorDisplaySfml::disp_memory);
    _disp_mod_ptr.push_back(&MonitorDisplaySfml::disp_network);
    _disp_mod_ptr.push_back(&MonitorDisplaySfml::disp_memorydisk);
    _disp_mod_ptr.push_back(&MonitorDisplaySfml::disp_uptime);
    _disp_mod_ptr.push_back(&MonitorDisplaySfml::disp_task);
    _disp_mod_ptr.push_back(&MonitorDisplaySfml::disp_sensors);
}

void MonitorDisplaySfml::disp_legend(void)
{
    sf::Text legend;
    sf::Font font;
    sf::RectangleShape rectangle;

    if (!font.loadFromFile("display/sfml/assets/fonts/arial.ttf"))
    {
        std::cerr << "Error: disp_mod_func: disp_memory: 132: fail to load display font" << std::endl;
        return;
    }

    rectangle.setSize(sf::Vector2f(280, 320));
    rectangle.setOutlineColor(sf::Color(255, 255, 255, 80));
    rectangle.setFillColor(sf::Color(255, 255, 255, 40));
    rectangle.setOutlineThickness(5);
    rectangle.setPosition(1620, 720);
    _window.draw(rectangle);

    legend.setFont(font);
    legend.setString("Modules Activation\n\n\
    H = Hostname\n\
    S = System\n\
    T = Date & Time\n\
    P = CPU\n\
    M = Memory\n\
    N = Network\n\
    D = Disk\n\
    U = Uptime\n\
    J = Task\n\
    O = Sensor");
    legend.setCharacterSize(20);
    legend.setFillColor(sf::Color::White);
    legend.setStyle(sf::Text::Bold);
    legend.setPosition(sf::Vector2f(1630, 750));
    _window.draw(legend);
}