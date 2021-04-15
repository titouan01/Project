/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** FileSystem
*/

#ifndef FILESYSTEM_HPP_
#define FILESYSTEM_HPP_

#include "../monitorCore/module.hpp"
#include <sys/statvfs.h>
#include <iostream>

class FileSystem : public IMonitorModule {
    public:
        FileSystem();

        void switchModule(void);
        void refresh(void);

        bool isActivated(void) const {return (_isEnabled);}
        int getModuleType(void) const {return (_moduleType);}
        float getTotalSpace(void) const {return (_totalSpace);}
        float getFreeSpace(void) const {return (_freeSpace);}

        ~FileSystem();

    protected:
    private:
        bool _isEnabled;
        int _moduleType;
        float _totalSpace;
        float _freeSpace;
};

#endif /* !FILESYSTEM_HPP_ */
