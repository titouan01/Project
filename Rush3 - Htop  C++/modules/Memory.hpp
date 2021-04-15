/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Memory
*/

#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include "../monitorCore/module.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

class Memory : public IMonitorModule {
    public:
        Memory();

        void switchModule(void);
        void refresh(void);

        bool isActivated(void) const {return (_isEnabled);}
        int getModuleType(void) const {return (_moduleType);}
        float getMemoryTotal(void) const {return (_memoryTotal);}
        float getMemoryFree(void) const {return (_memoryFree);}
        float getMemoryAvailable(void) const {return (_memoryAvailable);}
        float getSwapTotal(void) const {return (_swapTotal);}
        float getSwapFree(void) const {return (_swapFree);}

        ~Memory();

    protected:
    private:
        float _memoryTotal;
        float _memoryFree;
        float _memoryAvailable;
        float _swapTotal;
        float _swapFree;
        bool _isEnabled;
        int _moduleType;
};

#endif /* !MEMORY_HPP_ */
