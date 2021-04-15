/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush3-louis.boulet
** File description:
** Uptime
*/

#ifndef UPTIME_HPP_
#define UPTIME_HPP_

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "../monitorCore/module.hpp"

class Uptime : public IMonitorModule
{
public:
    Uptime();
    ~Uptime();
    void refresh(void);
    void switchModule(void);
    int getModuleType(void) const {return (_moduleType);}
    int getUpTime(void) const {return _uptime;}
    bool isActivated(void) const { return (_isEnabled); }

private:
    bool _isEnabled;
    int _moduleType;
    int _uptime;
};

#endif /* !UPTIME_HPP_ */
