
/*
** EPITECH PROJECT, 2021
** display modules functions
** File description:
** file
*/

#include "../../modules/HostnameModule.hpp"
#include "../../modules/Systeminfo.hpp"
#include "../../modules/Datetime.hpp"
#include "../../modules/CpuInfo.hpp"
#include "../../modules/Memory.hpp"
#include "../../modules/Network.hpp"
#include "../../modules/FileSystem.hpp"
#include "../../modules/Uptime.hpp"
#include "../../modules/Task.hpp"
#include "../../modules/Sensors.hpp"
#include "disp_obj.hpp"
#include "disp_mod_func.hpp"
#include "DisplaySfml.hpp"

void MonitorDisplaySfml::disp_hostname(sf::RenderWindow &window, IMonitorModule *module)
{
    HostnameModule *host_module = dynamic_cast<HostnameModule *>(module);
    sf::Text text_hostname;
    sf::Text text_username;
    sf::Font font;
    sf::RectangleShape rectangle;

    if (!font.loadFromFile("display/sfml/assets/fonts/arial.ttf"))
    {
        std::cerr << "Error: disp_mod_func: disp_cpu: 16: fail to load display font" << std::endl;
        return;
    }
    disp_bg_rectangle(window, rectangle, sf::Vector2f(550, 40), sf::Color(255, 255, 255, 80), sf::Color(255, 255, 255, 40), 5, sf::Vector2f(10, 15));
    disp_text(window, text_hostname, font, host_module->getHostname(), 24, sf::Color::White, sf::Text::Bold, sf::Vector2f(280, 18));
    disp_text(window, text_username, font, host_module->getUsername(), 24, sf::Color::White, sf::Text::Bold, sf::Vector2f(20, 18));
}

void MonitorDisplaySfml::disp_systeminfo(sf::RenderWindow &window, IMonitorModule *module)
{
    SystemInfo *systeminfo = dynamic_cast<SystemInfo *>(module);
    sf::Text text_opsys;
    sf::Text text_kernel;
    sf::Font font;
    sf::RectangleShape rectangle;

    if (!font.loadFromFile("display/sfml/assets/fonts/arial.ttf"))
    {
        std::cerr << "Error: disp_mod_func: disp_systemeinfo: 65: fail to load display font" << std::endl;
        return;
    }
    disp_bg_rectangle(window, rectangle, sf::Vector2f(400, 40), sf::Color(255, 255, 255, 80), sf::Color(255, 255, 255, 40), 5, sf::Vector2f(580, 15));
    disp_text(window, text_opsys, font, systeminfo->getOpSys(), 24, sf::Color::White, sf::Text::Bold, sf::Vector2f(600, 18));
    disp_text(window, text_kernel, font, systeminfo->getKernel(), 24, sf::Color::White, sf::Text::Bold, sf::Vector2f(700, 18));
}

void MonitorDisplaySfml::disp_datetime(sf::RenderWindow &window, IMonitorModule *module)
{
    Datetime *datetime = dynamic_cast<Datetime *>(module);
    sf::Text text_time;
    sf::Text text_date;
    sf::Font font;
    sf::RectangleShape rectangle;

    if (!font.loadFromFile("display/sfml/assets/fonts/arial.ttf"))
    {
        std::cerr << "Error: disp_mod_func: disp_datetime: 100: fail to load display font" << std::endl;
        return;
    }
    disp_bg_rectangle(window, rectangle, sf::Vector2f(280, 40), sf::Color(255, 255, 255, 80), sf::Color(255, 255, 255, 40), 5, sf::Vector2f(1620, 15));
    disp_text(window, text_time, font, datetime->getTime(), 24, sf::Color::White, sf::Text::Bold, sf::Vector2f(1780, 18));
    disp_text(window, text_time, font, datetime->getDate(), 24, sf::Color::White, sf::Text::Bold, sf::Vector2f(1620, 18));
}

void MonitorDisplaySfml::disp_memory(sf::RenderWindow &window, IMonitorModule *module)
{
    Memory *memory = dynamic_cast<Memory *>(module);
    sf::RectangleShape rectangle;
    sf::RectangleShape rectangle_legend;
    sf::RectangleShape total_legend;
    sf::RectangleShape free_legend;
    sf::RectangleShape available_legend;
    sf::RectangleShape memory_total;
    sf::RectangleShape memory_free;
    sf::RectangleShape memory_available;
    sf::RectangleShape swap_total;
    sf::RectangleShape swap_free;
    sf::Text module_title;
    sf::Text swap_title;
    sf::Text memory_legend;
    sf::Text memory_utilisation;
    sf::Text swap_utilisation;
    sf::Font font;

    if (!font.loadFromFile("display/sfml/assets/fonts/arial.ttf"))
    {
        std::cerr << "Error: disp_mod_func: disp_memory: 132: fail to load display font" << std::endl;
        return;
    }

    disp_bg_rectangle(window, rectangle, sf::Vector2f(800, 230), sf::Color(255, 255, 255, 80), sf::Color(255, 255, 255, 40), 5, sf::Vector2f(10, 75));
    disp_bg_rectangle(window, rectangle_legend, sf::Vector2f(150, 230), sf::Color(255, 255, 255, 80), sf::Color(255, 255, 255, 40), 5, sf::Vector2f(830, 75));

    disp_rectangle(window, total_legend, sf::Vector2f(30, 20), sf::Color::Red, sf::Vector2f(840, 100));
    disp_rectangle(window, free_legend, sf::Vector2f(30, 20), sf::Color::Green, sf::Vector2f(840, 170));
    disp_rectangle(window, available_legend, sf::Vector2f(30, 20), sf::Color::Blue, sf::Vector2f(840, 240));

    disp_rectangle(window, memory_total, sf::Vector2f(740, 40), sf::Color::Red, sf::Vector2f(40, 120));
    disp_rectangle(window, memory_available, sf::Vector2f((memory->getMemoryAvailable() * 740) / memory->getMemoryTotal(), 40), sf::Color::Blue, sf::Vector2f(40 + memory->getMemoryFree() * 90, 120));
    disp_rectangle(window, memory_free, sf::Vector2f((memory->getMemoryFree() * 740) / memory->getMemoryTotal(), 40), sf::Color::Green, sf::Vector2f(40, 120));
    disp_rectangle(window, swap_total, sf::Vector2f(740, 40), sf::Color::Red, sf::Vector2f(40, 240));
    disp_rectangle(window, swap_free, sf::Vector2f((memory->getSwapFree() * 740) / memory->getSwapTotal(), 40), sf::Color::Green, sf::Vector2f(40, 240));

    disp_text(window, memory_utilisation, font, "Memory size: " + std::to_string(memory->getMemoryTotal()) + "   Memory used: " + std::to_string((memory->getMemoryTotal() - memory->getMemoryFree() - memory->getMemoryAvailable()) * 100 / memory->getMemoryTotal()), 14, sf::Color::White, sf::Text::Bold, sf::Vector2f(50, 160));
    disp_text(window, memory_legend, font, "\tTotal\n\n\n\tFree\n\n\n\tAvailable", 20,  sf::Color::White, sf::Text::Bold, sf::Vector2f(835, 120));
    disp_text(window, module_title, font, "Memory :", 24, sf::Color::White, sf::Text::Bold, sf::Vector2f(20, 78));
    disp_text(window, swap_title, font, "Swap :", 24, sf::Color::White, sf::Text::Bold, sf::Vector2f(20, 200));
}

void MonitorDisplaySfml::disp_cpu(sf::RenderWindow &window, IMonitorModule *module)
{
    CpuInfo *cpuinfo = dynamic_cast<CpuInfo *>(module);
    sf::RectangleShape rectangle;
    sf::RectangleShape total_cpu;
    sf::RectangleShape used_cpu;
    sf::Text cpu_data;
    sf::Text cpu_pourcent;
    sf::Font font;

    if (!font.loadFromFile("display/sfml/assets/fonts/arial.ttf"))
    {
        std::cerr << "Error: disp_mod_func: disp_memory: 132: fail to load display font" << std::endl;
        return;
    }
    _cpu_pourcent->refresh();
    disp_bg_rectangle(window, rectangle, sf::Vector2f(970, 200), sf::Color(255, 255, 255, 80), sf::Color(255, 255, 255, 40), 5, sf::Vector2f(10, 485));
    disp_rectangle(window, total_cpu, sf::Vector2f(740, 40), sf::Color::Blue, sf::Vector2f(40, 620));
    disp_rectangle(window, used_cpu, sf::Vector2f((_cpu_pourcent->getCorePercent() * 740) / 100, 40), sf::Color::White, sf::Vector2f(40, 620));
    disp_text(window, cpu_pourcent, font, std::to_string((int)std::round(_cpu_pourcent->getCorePercent())) + "%", 24, sf::Color::White, sf::Text::Bold, sf::Vector2f(800, 630));
    disp_text(window, cpu_data, font, "CPU :\n\n\tType = " + cpuinfo->getCPUModel() + "\n\tCore number: " + std::to_string(cpuinfo->getCoreNb()), 24, sf::Color::White, sf::Text::Bold, sf::Vector2f(20, 488));
}

void MonitorDisplaySfml::disp_network(sf::RenderWindow &window, IMonitorModule *module)
{
    Network *network = dynamic_cast<Network *>(module);
    sf::RectangleShape rectangle;
    sf::Text network_title;
    sf::Text up;
    sf::Text down;
    sf::Font font;

    if (!font.loadFromFile("display/sfml/assets/fonts/arial.ttf"))
    {
        std::cerr << "Error: disp_mod_func: disp_memory: 132: fail to load display font" << std::endl;
        return;
    }
    disp_bg_rectangle(window, rectangle, sf::Vector2f(280, 230), sf::Color(255, 255, 255, 80), sf::Color(255, 255, 255, 40), 5, sf::Vector2f(1620, 75));

    disp_text(window, network_title, font, "Network :", 24, sf::Color::White, sf::Text::Bold, sf::Vector2f(1630, 78));
    disp_text(window, up, font, "Up\n\t" + std::to_string(network->getUpNetMb()) + " Mb/s", 24, sf::Color::White, sf::Text::Bold, sf::Vector2f(1645, 140));
    disp_text(window, down, font, "Down\n\t" + std::to_string(network->getDownNetMb()) + " Mb/s", 24, sf::Color::White, sf::Text::Bold, sf::Vector2f(1645, 200));
}

void MonitorDisplaySfml::disp_memorydisk(sf::RenderWindow &window, IMonitorModule *module)
{
    FileSystem *filesystem = dynamic_cast<FileSystem *>(module);
    sf::RectangleShape rectangle;
    sf::RectangleShape total_space;
    sf::RectangleShape used_space;
    sf::RectangleShape rectangle_legend;
    sf::RectangleShape total_legend;
    sf::RectangleShape used_legend;
    sf::Text memorydisk_title;
    sf::Text memorydisk_data;
    sf::Text memorydisk_legend;
    sf::Font font;

    if (!font.loadFromFile("display/sfml/assets/fonts/arial.ttf"))
    {
        std::cerr << "Error: disp_mod_func: disp_memory: 132: fail to load display font" << std::endl;
        return;
    }
    disp_bg_rectangle(window, rectangle, sf::Vector2f(800, 140), sf::Color(255, 255, 255, 80), sf::Color(255, 255, 255, 40), 5, sf::Vector2f(10, 325));
    disp_bg_rectangle(window, rectangle_legend, sf::Vector2f(150, 140), sf::Color(255, 255, 255, 80), sf::Color(255, 255, 255, 40), 5, sf::Vector2f(830, 325));
    disp_rectangle(window, total_space, sf::Vector2f(740, 40), sf::Color::Blue, sf::Vector2f(40, 365));
    disp_rectangle(window, used_space, sf::Vector2f((((filesystem->getTotalSpace() - filesystem->getFreeSpace())) * 740) / filesystem->getTotalSpace(), 40), sf::Color::White, sf::Vector2f(40, 365));
    disp_rectangle(window, total_legend, sf::Vector2f(30, 20), sf::Color::Blue, sf::Vector2f(840, 350));
    disp_rectangle(window, used_legend, sf::Vector2f(30, 20), sf::Color::White, sf::Vector2f(840, 400));
    disp_text(window, memorydisk_title, font, "Memory disk:", 24, sf::Color::White, sf::Text::Bold, sf::Vector2f(20, 328));
    disp_text(window, memorydisk_data, font, "Total space: " + std::to_string((int)std::round(filesystem->getTotalSpace())) + " go   Used space: " + std::to_string((int)std::round(filesystem->getTotalSpace() - filesystem->getFreeSpace())) + " go", 14, sf::Color::White, sf::Text::Bold, sf::Vector2f(20, 415));
    disp_text(window, memorydisk_legend, font, "\tTotal\n\n\tUsed", 20, sf::Color::White, sf::Text::Bold, sf::Vector2f(835, 370));
}

void MonitorDisplaySfml::disp_uptime(sf::RenderWindow &window, IMonitorModule *module)
{
    Uptime *uptime = dynamic_cast<Uptime *>(module);
    sf::RectangleShape rectangle;
    sf::Text uptime_data;
    sf::Font font;

    if (!font.loadFromFile("display/sfml/assets/fonts/arial.ttf"))
    {
        std::cerr << "Error: disp_mod_func: disp_memory: 132: fail to load display font" << std::endl;
        return;
    }

    disp_bg_rectangle(window, rectangle, sf::Vector2f(280, 110), sf::Color(255, 255, 255, 80), sf::Color(255, 255, 255, 40), 5, sf::Vector2f(1620, 325));
    disp_text(window, uptime_data, font, "Up Time:\n\t" + std::to_string(uptime->getUpTime() / 60) + "h " + std::to_string(uptime->getUpTime() % 60) + "min", 24, sf::Color::White, sf::Text::Bold, sf::Vector2f(1630, 345));
}

void MonitorDisplaySfml::disp_task(sf::RenderWindow &window, IMonitorModule *module)
{
    Task *task = dynamic_cast<Task *>(module);
    sf::RectangleShape rectangle;
    sf::Text task_data;
    sf::Font font;

    if (!font.loadFromFile("display/sfml/assets/fonts/arial.ttf"))
    {
        std::cerr << "Error: disp_mod_func: disp_memory: 132: fail to load display font" << std::endl;
        return;
    }

    disp_bg_rectangle(window, rectangle, sf::Vector2f(280, 110), sf::Color(255, 255, 255, 80), sf::Color(255, 255, 255, 40), 5, sf::Vector2f(1620, 455));
    disp_text(window, task_data, font, "Tasks:\n\ttask number = " + std::to_string(task->getNbTasks()), 24, sf::Color::White, sf::Text::Bold, sf::Vector2f(1630, 475));
}

void MonitorDisplaySfml::disp_sensors(sf::RenderWindow &window, IMonitorModule *module)
{
    Sensors *sensors = dynamic_cast<Sensors *>(module);
    sf::RectangleShape rectangle;
    sf::Text sensors_data;
    sf::Font font;

    if (!font.loadFromFile("display/sfml/assets/fonts/arial.ttf"))
    {
        std::cerr << "Error: disp_mod_func: disp_memory: 132: fail to load display font" << std::endl;
        return;
    }

    disp_bg_rectangle(window, rectangle, sf::Vector2f(280, 110), sf::Color(255, 255, 255, 80), sf::Color(255, 255, 255, 40), 5, sf::Vector2f(1620, 585));
    disp_text(window, sensors_data, font, "Temperature:\n\t" + std::to_string(sensors->getTemperature()) + " Degres Celcius", 24, sf::Color::White, sf::Text::Bold, sf::Vector2f(1630, 600));
}