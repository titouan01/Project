/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Datetime
*/

#include "Datetime.hpp"

Datetime::Datetime()
{
    this->_isEnabled = true;
    this->_moduleType = DATETIME;
    this->_date = "";
    this->_time = "";
}

void Datetime::switchModule(void)
{
    this->_isEnabled = !this->_isEnabled;
}

void Datetime::refresh(void)
{
    if (!this->_isEnabled)
        return;

    std::ifstream file("/proc/driver/rtc");
    std::string line;
    std::size_t index;

    if (file.fail()) {
        this->_date = "Error";
        this->_time = "Error";
        return;
    }
    if (std::getline(file, line)) {
        index = line.find(":") + 1;
        this->_time = line.substr(index);
    } else {
        this->_time = "Error";
    }
    if (std::getline(file, line)) {
        index = line.find(":") + 1;
        this->_date = line.substr(index);
    } else {
        this->_date = "Error";
    }
    file.close();
}

Datetime::~Datetime()
{
}
