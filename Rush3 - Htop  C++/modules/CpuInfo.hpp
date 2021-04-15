/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush3-louis.boulet
** File description:
** CpuInfo
*/

#ifndef CpuInfo_HPP_
#define CpuInfo_HPP_

#include <string>
#include "../monitorCore/module.hpp"
#include <fstream>

class CpuInfo : public IMonitorModule
{
public:
    CpuInfo();
    virtual ~CpuInfo();
    void refresh(void);
    void switchModule(void);
    std::string getCPUModel() const;
    bool isActivated(void) const {return (_isEnabled);}
    int getModuleType(void) const { return (_moduleType); }
    int getCoreNb() const;
    float *getCorePercent() const;
    void defineCPUModel(std::string);
    void defineCoreNb(int core);
    void defineCorePercent(float *);

private:
    bool _isEnabled;
    int _moduleType;
    std::string _CPUModel;
    int _coreNb;
    float _useCPU;
};
#endif /* !CpuInfo_HPP_ */
