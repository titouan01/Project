/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush3-louis.boulet
** File description:
** systeminfo
*/

#ifndef SYSTEMINFO_HPP_
#define SYSTEMINFO_HPP_

#include <string>
#include "../monitorCore/module.hpp"

class SystemInfo : public IMonitorModule
{
public:
    SystemInfo();
    virtual ~SystemInfo();
    std::string getOpSys() const;
    std::string getKernel() const;
    void refresh(void);
    void switchModule(void);
    void defineOpSys(std::string);
    void defineKernel(std::string);
    int getModuleType(void) const {return (_moduleType);}
    bool isActivated(void) const {return (_isEnabled);}

private:
    bool _isEnabled;
    int _moduleType;
    std::string _opSys;
    std::string _kernel;
};

#endif /* !SYSTEMINFO_HPP_ */
