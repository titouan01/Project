/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush3-louis.boulet
** File description:
** ncurse
*/

#ifndef NCURSE_HPP_
#define NCURSE_HPP_

#include "../../monitorCore/moduleType.hpp"
#include "../../monitorCore/IMonitorDisplay.hpp"
#include "../../modules/CpuPourcent.hpp"
#include "../../modules/HostnameModule.hpp"
#include "../../modules/Datetime.hpp"
#include "../../modules/Memory.hpp"
#include "../../modules/Systeminfo.hpp"
#include "../../modules/CpuInfo.hpp"
#include "../../modules/Network.hpp"
#include "../../modules/Sensors.hpp"
#include "../../modules/FileSystem.hpp"
#include "../../modules/Task.hpp"
#include "../../modules/Uptime.hpp"
#include <ncurses.h>
#include <vector>
#include <iostream>
#include <string>

class ncurse : public IMonitorDisplay
{
    using listFunctionPointer = void (ncurse::*)(IMonitorModule*);
    
    public:
        ncurse();
        ~ncurse();
        void displayModules();
        void refreshModules(void);
        void run(void);
        bool handleKey(void);
        void resetWindow(void);
        void toggleModule(int type);

        //All display functions for module
        void dispHostName(IMonitorModule*);
        void dispDateTime(IMonitorModule*);
        void dispMemory(IMonitorModule*);
        void dispsysteminfo(IMonitorModule*);
        void dispGPU(IMonitorModule*);
        void dispNetwork(IMonitorModule*);
        void dispfileSystem(IMonitorModule*);
        void dispSensors(IMonitorModule*);
        void dispTask(IMonitorModule*);
        void dispUptime(IMonitorModule*);
        int dispPartBar(float memTotal, float memNode, float size, chtype color);
    protected:
    private:
        
        std::vector<IMonitorModule*> _modules;
        std::vector<listFunctionPointer> _functionModules;
        CpuPourcent *pourcent = new CpuPourcent;
        WINDOW *window;
        int _width = 1200;
        int _height = 1200;
        int posCursor_X = 1;
        int posCursor_Y = 3;
        float MbUp = 0;
        float MbDown = 0;
        float MbUpDiff = 0;
        float MbDownDiff = 0;
};


#endif /* !NCURSE_HPP_ */
