/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Memory
*/

#include "Memory.hpp"

Memory::Memory()
{
    this->_memoryTotal = 0.0f;
    this->_memoryFree = 0.0f;
    this->_memoryAvailable = 0.0f;
    this->_swapTotal = 0.0f;
    this->_swapFree = 0.0f;
    this->_moduleType = RAM;
    this->_isEnabled = true;
}

void Memory::switchModule(void)
{
    this->_isEnabled = !this->_isEnabled;
}

void Memory::refresh(void)
{
    if (!this->_isEnabled)
        return;

    std::ifstream file("/proc/meminfo");
    std::string line;
    int value;

    if (!file.is_open()) {
        this->_memoryTotal = 0.0f;
        this->_memoryFree = 0.0f;
        this->_memoryAvailable = 0.0f;
        this->_swapTotal = 0.0f;
        this->_swapFree = 0.0f;
        return;
    }
    while (std::getline(file, line)) {
        if ((int) line.find("MemTotal:") != -1) {
            std::stringstream(line.substr(line.find(":") + 1)) >> value;
            this->_memoryTotal = ((float) value / 1000000.0f);
            continue;
        }
        if ((int) line.find("MemFree:") != -1) {
            std::stringstream(line.substr(line.find(":") + 1)) >> value;
            this->_memoryFree = ((float) value / 1000000.0f);
            continue;
        }
        if ((int) line.find("MemAvailable:") != -1) {
            std::stringstream(line.substr(line.find(":") + 1)) >> value;
            this->_memoryAvailable = ((float) value / 1000000.0f);
            continue;
        }
        if ((int) line.find("SwapTotal:") != -1) {
            std::stringstream(line.substr(line.find(":") + 1)) >> value;
            this->_swapTotal = ((float) value / 1000000.0f);
            continue;
        }
        if ((int) line.find("SwapFree:") != -1) {
            std::stringstream(line.substr(line.find(":") + 1)) >> value;
            this->_swapFree = ((float) value / 1000000.0f);
            continue;
        }
    }
    file.close();
}

Memory::~Memory()
{
}
