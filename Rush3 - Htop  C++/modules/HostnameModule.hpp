/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** HostnameModule
*/

#ifndef HOSTNAMEMODULE_HPP_
#define HOSTNAMEMODULE_HPP_

#include <fstream>
#include "../monitorCore/module.hpp"

class HostnameModule : public IMonitorModule {
    public:
        HostnameModule();

        void switchModule(void);
        void refresh(void);

        bool isActivated(void) const {return (_isEnabled);}
        int getModuleType(void) const {return (_moduleType);}
        std::string getUsername(void) const {return (_username);}
        std::string getHostname(void) const {return (_hostname);}

        ~HostnameModule();

    protected:
    private:
        bool _isEnabled;
        int _moduleType;
        std::string _hostname;
        std::string _username;
};

#endif /* !HOSTNAMEMODULE_HPP_ */
