/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush3-louis.boulet
** File description:
** CpuInfo
*/

#include "CpuInfo.hpp"

void CpuInfo::defineCPUModel(std::string model) { this->_CPUModel = model; }
void CpuInfo::defineCoreNb(int coreNb) { this->_coreNb = coreNb; }
std::string CpuInfo::getCPUModel() const { return (this->_CPUModel); }
int CpuInfo::getCoreNb() const { return (this->_coreNb); }

CpuInfo::CpuInfo()
{
    this->_isEnabled = true;
    this->_moduleType = CPU;
    this->_CPUModel = "";
    this->_coreNb = 0;
}

std::string parsingCPU(const std::string str)
{
    unsigned int i = 0;
    std::string ret;

    while (str[i] != ':')
        i++;
    i += 2;
    while (i < str.length())
        ret += str[i++];
    return (ret);
}

void CpuInfo::refresh(void)
{
    std::string path = "/proc/cpuinfo";
    std::string str, line;
    std::ifstream file(path.c_str(), std::ios::in);
    this->defineCoreNb(0);
    if (file) {
        while (getline(file, line)) {
            if (line.find("model name") != std::string::npos)
                this->defineCPUModel(parsingCPU(line));
            else if (line.find("processor") != std::string::npos)
                this->defineCoreNb(this->getCoreNb() + 1);
        }
    }
}

void CpuInfo::switchModule(void)
{
    this->_isEnabled = !this->_isEnabled;
}

CpuInfo::~CpuInfo()
{
}