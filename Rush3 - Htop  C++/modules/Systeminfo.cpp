/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush3-louis.boulet
** File description:
** systeminfo
*/

#include "Systeminfo.hpp"
#include <sys/utsname.h>
#include <iostream>
#include <fstream>
#include <string>

void SystemInfo::defineOpSys(std::string opSys) { this->_opSys = opSys; }
void SystemInfo::defineKernel(std::string kernel) { this->_kernel = kernel; }
std::string SystemInfo::getOpSys() const { return (this->_opSys); }
std::string SystemInfo::getKernel() const { return (this->_kernel); }

SystemInfo::SystemInfo()
{
    this->_isEnabled = true;
    this->_moduleType = OPERATING_SYSTEM;
    this->_opSys = "";
    this->_kernel = "";
}

void SystemInfo::refresh(void)
{
    struct utsname unameData;
    std::string k_name = "ERROR";
    std::string k_vers = "ERROR";
    if (uname(&unameData) != -1)
    {
        k_name = unameData.sysname;
        k_vers = unameData.release;
    }
    this->defineOpSys(k_name);
    this->defineKernel(k_vers);
}

void SystemInfo::switchModule(void)
{
    this->_isEnabled = !this->_isEnabled;
}

SystemInfo::~SystemInfo()
{
}