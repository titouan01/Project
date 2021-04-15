// /*
// ** EPITECH PROJECT, 2021
// ** B-CPP-300-MPL-3-1-CPPrush3-louis.boulet
// ** File description:
// ** CpuPourcent
// */

#ifndef CPUPOURCENT_HPP_
#define CPUPOURCENT_HPP_

#include <string>
#include "../monitorCore/module.hpp"
#include <fstream>
#include <fstream>
#include <iostream>
#include <numeric>
#include <unistd.h>
#include <vector>
class CpuPourcent
{
public:
    CpuPourcent(void);
    ~CpuPourcent(void);
    void refresh(void);
    void switchModule(void);
    int getModuleType(void) const { return (_moduleType); }
    bool isActivated(void) const { return (_isEnabled); }
    void defineCorePercent(float);
    float getCorePercent() const;

    // return :
    // % of cpu usage for this process
    // % cpu systemUsage
    // uptime for this process
private:
    bool _isEnabled;
    int _moduleType;
    float _useCPU;
    size_t previous_idle_time = 0; 
    size_t previous_total_time = 0;

};

#endif /* !CPUPOURCENT_HPP_ */
