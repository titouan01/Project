/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** FileSystem
*/

#include "FileSystem.hpp"

FileSystem::FileSystem()
{
    this->_isEnabled = true;
    this->_moduleType = MEMORYDISK;
    this->_totalSpace = 0.0f;
    this->_freeSpace = 0.0f;
}

void FileSystem::switchModule(void)
{
    this->_isEnabled = !this->_isEnabled;
}

void FileSystem::refresh(void)
{
    if (!this->_isEnabled)
        return;

    struct statvfs diskData;

    if (statvfs("/", &diskData) < 0) {
        this->_totalSpace = 0.0f;
        this->_freeSpace = 0.0f;
    } else {
        this->_totalSpace = (diskData.f_blocks * diskData.f_bsize) / 1000000000.0f;
        this->_freeSpace = (diskData.f_bfree * diskData.f_bsize) / 1000000000.0f;
    }
}

FileSystem::~FileSystem()
{
}
