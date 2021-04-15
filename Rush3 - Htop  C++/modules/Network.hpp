/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <fstream>
#include <sstream>
#include <iostream>
#include "../monitorCore/module.hpp"

class Network : public IMonitorModule {
    public:
        Network();

        void switchModule(void);
        void refresh(void);
        void setUpNetMb(float up);
        void setDownNetMb(float down);

        bool isActivated(void) const {return (_isEnabled);}
        int getModuleType(void) const {return (_moduleType);}
        float getUpNet(void) const {return (_upNet);}
        float getDownNet(void) const {return (_downNet);}
        float getUpNetMb(void) const {return (_upNetMb);}
        float getDownNetMb(void) const {return (_downNetMb);}

        ~Network();

    protected:
    private:
        bool _isEnabled;
        int _moduleType;
        float _upNetMb;
        float _downNetMb;
        float _upNet;
        float _downNet;
};

#endif /* !NETWORK_HPP_ */
