/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush3-louis.boulet
** File description:
** Task
*/

#include "Task.hpp"

int Task::getNbTasks() const { return (this->_nbtask); }
void Task::defineNbTasks(int tasksNb) { this->_nbtask = tasksNb; }

Task::Task()
{
    this->_isEnabled = true;
    this->_moduleType = TASK;
    this->_nbtask = 0;
}

void Task::refresh(void)
{
     DIR* dir;

    if(!(dir = opendir("/proc")))
        throw std::runtime_error(std::strerror(errno));

    std::size_t count = 0;

    while(dirent* dirp = readdir(dir))
    {
        if(dirp->d_type != DT_DIR)
            continue;
        if(!std::all_of(dirp->d_name, dirp->d_name + std::strlen(dirp->d_name),
            [](char c){ return std::isdigit(c); }))
                continue;
        ++count;
    }

    if(closedir(dir))
        throw std::runtime_error(std::strerror(errno));

    defineNbTasks(count / 2 + 47 );
}

void Task::switchModule(void)
{
    this->_isEnabled = !this->_isEnabled;
}

Task::~Task()
{
}
