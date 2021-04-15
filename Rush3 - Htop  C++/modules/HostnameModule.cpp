/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** HostnameModule
*/

#include "HostnameModule.hpp"

HostnameModule::HostnameModule()
{
    this->_isEnabled = true;
    this->_moduleType = HOSTNAME;
    this->_hostname = "";
    this->_username = "";
}

void HostnameModule::switchModule(void)
{
    this->_isEnabled = !this->_isEnabled;
}

void HostnameModule::refresh(void)
{
    std::ifstream file("/proc/sys/kernel/hostname");

    if (!this->_isEnabled)
        return;
    this->_username = getenv("USER");
    if (!file.is_open()) {
        this->_hostname = "Error";
    } else {
        std::getline(file, this->_hostname);
        file.close();
    }
}

HostnameModule::~HostnameModule()
{
}
