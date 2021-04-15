/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Sensors
*/

#include "Sensors.hpp"

Sensors::Sensors()
{
    this->_isEnabled = true;
    this->_moduleType = SENSOR;
    this->_temperature = 0;
    this->_temperatureCrit = 0;
}

void Sensors::switchModule(void)
{
    this->_isEnabled = !this->_isEnabled;
}

void Sensors::refresh(void)
{
    if (!this->_isEnabled)
        return;

    std::ifstream fileTemp("/sys/class/thermal/thermal_zone0/hwmon1/temp1_input");
    std::ifstream fileCrit("/sys/class/thermal/thermal_zone0/hwmon1/temp1_crit");
    std::string line;
    int value;

    if (!fileTemp.is_open() || !fileCrit.is_open())
        return;
    if (std::getline(fileTemp, line)) {
        std::stringstream(line) >> value;
        this->_temperature = value / 1000;
    }
    if (std::getline(fileCrit, line)) {
        std::stringstream(line) >> value;
        this->_temperatureCrit = value / 1000;
    }
    fileTemp.close();
    fileCrit.close();
}

Sensors::~Sensors()
{
}
