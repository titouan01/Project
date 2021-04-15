/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <map>

class IMonitorModule {
    public:
        virtual void switchModule(void) = 0;
        virtual void refresh(void) = 0;

        // GETTERS
        virtual bool isActivated(void) const = 0;
        virtual int getModuleType(void) const = 0;

        virtual ~IMonitorModule() = default;
    protected:
    private:
};

#endif /* !IMONITORMODULE_HPP_ */
