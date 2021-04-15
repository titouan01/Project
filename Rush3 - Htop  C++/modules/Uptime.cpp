/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush3-louis.boulet
** File description:
** Uptime
*/

#include "Uptime.hpp"

Uptime::Uptime()
{
    this->_isEnabled = true;
    this->_moduleType = UPTIME;
    this->_uptime = 0;
}

void Uptime::refresh(void)
{
    std::ifstream file("/proc/uptime");
    std::string line;
    if (file.fail()) {
        this->_uptime = 0;
        return;
    }
    if (std::getline(file, line)){
        this->_uptime = atoi(line.c_str());
        this->_uptime = _uptime / 120;
        }
    file.close();
}

void Uptime::switchModule(void)
{
    this->_isEnabled = !this->_isEnabled;
}

Uptime::~Uptime()
{
}