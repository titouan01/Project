/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush3-louis.boulet
** File description:
** Task
*/

#ifndef TASK_HPP_
#define TASK_HPP_

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h>
#include "../monitorCore/module.hpp"
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <algorithm>
#include <stdexcept>
#include <cerrno>
#include <cstring>
#include <dirent.h>

class Task : public IMonitorModule
{
public:
    Task();
    virtual ~Task();
    void refresh(void);
    void defineNbTasks(int);
    int getNbTasks() const;
    void switchModule(void);
    int getModuleType(void) const {return (_moduleType);}
    bool isActivated(void) const { return (_isEnabled); }

private:
    bool _isEnabled;
    int _moduleType;
    int _nbtask;
};

#endif /* !TASK_HPP_ */
