/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Datetime
*/

#ifndef DATETIME_HPP_
#define DATETIME_HPP_

#include "../monitorCore/module.hpp"
#include <fstream>

class Datetime : public IMonitorModule {
    public:
        Datetime();

        void switchModule(void);
        void refresh(void);

        bool isActivated(void) const {return (_isEnabled);}
        int getModuleType(void) const {return (_moduleType);}
        std::string getDate(void) const {return (_date);}
        std::string getTime(void) const {return (_time);}

        ~Datetime();

    protected:
    private:
        bool _isEnabled;
        int _moduleType;
        std::string _date;
        std::string _time;
};

#endif /* !DATETIME_HPP_ */
