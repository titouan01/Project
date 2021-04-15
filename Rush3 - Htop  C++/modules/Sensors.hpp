/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Sensors
*/

#ifndef SENSORS_HPP_
#define SENSORS_HPP_

#include "../monitorCore/module.hpp"
#include <fstream>
#include <sstream>

class Sensors : public IMonitorModule {
    public:
        Sensors();

        void switchModule(void);
        void refresh(void);

        bool isActivated(void) const {return (_isEnabled);}
        int getModuleType(void) const {return (_moduleType);}
        int getTemperature(void) const {return (_temperature);}
        int getTemperatureCrit(void) const {return (_temperatureCrit);}

        ~Sensors();

    protected:
    private:
        bool _isEnabled;
        int _moduleType;
        int _temperature;
        int _temperatureCrit;
};

#endif /* !SENSORS_HPP_ */
