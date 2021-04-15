/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Network
*/

#include "Network.hpp"

Network::Network()
{
    this->_isEnabled = true;
    this->_moduleType = NETWORK;
    this->_upNet = 0.0f;
    this->_downNet = 0.0f;
}

void Network::switchModule(void)
{
    this->_isEnabled = !this->_isEnabled;
}

void Network::refresh(void)
{
    if (!this->_isEnabled)
        return;

    std::ifstream file("/proc/net/dev");
    std::string line;
    unsigned long value;

    if (!file.is_open()) {
        this->_upNet = 0.0f;
        this->_downNet = 0.0f;
        return;
    }
    std::getline(file, line);
    std::getline(file, line);
    for (; std::getline(file, line);) {
        if ((int) line.find("wl") != -1) {
            std::stringstream(line.substr(line.find(":") + 1)) >> value;
            this->_downNet = (float) value / 1000000.0f;
            std::stringstream(line.substr(line.find(":") + 1)) >> value >> value >>
            value >> value >> value >> value >> value >> value >> value;
            this->_upNet = (float) value / 1000000.0f;
            break;
        }
    }

    file.close();
}

void Network::setUpNetMb(float up)
{
    this->_upNetMb = up;
}

void Network::setDownNetMb(float down)
{
    this->_downNetMb = down;
}

Network::~Network()
{
}
