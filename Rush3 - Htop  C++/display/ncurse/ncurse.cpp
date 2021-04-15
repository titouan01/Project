/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush3-louis.boulet
** File description:
** ncurse
*/

#include "ncurse.hpp"

ncurse::ncurse()
{
    HostnameModule *mod1 = new HostnameModule;
    Datetime *mod2 = new Datetime;
    Memory *mem1 = new Memory;
    CpuInfo *gpu = new CpuInfo;
    SystemInfo *system = new SystemInfo;
    Network *network = new Network;
    Sensors *sensor = new Sensors;
    FileSystem *filesystem = new FileSystem;
    Uptime *uptime = new Uptime;
    Task *task = new Task;
    this->_modules.push_back(mod2);
    this->_modules.push_back(mod1);
    this->_modules.push_back(system);
    this->_modules.push_back(gpu);
    this->_modules.push_back(sensor);
    this->_modules.push_back(uptime);
    this->_modules.push_back(mem1);
    this->_modules.push_back(filesystem);
    this->_modules.push_back(network);
    this->_modules.push_back(task);
    this->_functionModules.push_back(&ncurse::dispHostName);
    this->_functionModules.push_back(&ncurse::dispsysteminfo);
    this->_functionModules.push_back(&ncurse::dispDateTime);
    this->_functionModules.push_back(&ncurse::dispGPU);
    this->_functionModules.push_back(&ncurse::dispMemory);
    this->_functionModules.push_back(&ncurse::dispNetwork);
    this->_functionModules.push_back(&ncurse::dispfileSystem);
    this->_functionModules.push_back(&ncurse::dispUptime);
    this->_functionModules.push_back(&ncurse::dispTask);
    this->_functionModules.push_back(&ncurse::dispSensors);
}

ncurse::~ncurse()
{
    for (std::size_t i = 0; i < this->_modules.size(); i++) {
        delete this->_modules[i];
    }
    delete this->pourcent;

}

void ncurse::dispHostName(IMonitorModule* module)
{
    HostnameModule *_module = static_cast<HostnameModule*>(module);
    HostnameModule nameInfo = *_module;
    nameInfo.refresh();
    std::string hostName = nameInfo.getHostname();
    std::string userName = nameInfo.getUsername();
    mvwprintw(this->window, 1, 1, "%s : %s", hostName.c_str(), userName.c_str());
}

void ncurse::dispUptime(IMonitorModule* module)
{
    Uptime *uptime = static_cast<Uptime*>(module);
    Uptime uptimeInfo = *uptime;
    uptimeInfo.refresh();
    int heures = uptimeInfo.getUpTime();
    int minutes = heures/60;
    heures = heures % 60;
    mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, "Up since %dh %dm", minutes, heures);
    this->posCursor_Y += 1;
    
}

void ncurse::dispTask(IMonitorModule* module)
{
    Task *task = static_cast<Task*>(module);
    Task taskInfo = *task;
    taskInfo.refresh();
    int nbTask = taskInfo.getNbTasks();
    mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, "Task running : %d", nbTask);
    this->posCursor_Y += 1;
}

void ncurse::dispfileSystem(IMonitorModule* module)
{
    FileSystem *fileSystem = static_cast<FileSystem*>(module);
    FileSystem fileInfo = *fileSystem;
    fileInfo.refresh();
    float freeSpace = fileInfo.getFreeSpace();
    float totalSpace = fileInfo.getTotalSpace();
    float size = 40;
    this->posCursor_Y += 1;
    mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, "Memory disk [");
    this->posCursor_X += 13;
    int rest = this->dispPartBar(totalSpace, freeSpace, 40, COLOR_PAIR(3));
    for (int i = 0; i < (size - rest); i++) {
        wattron(this->window, COLOR_PAIR(2));
        mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, " ");
        wattroff(this->window, COLOR_PAIR(2));
        this->posCursor_X += 1;
    }
    mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, "] %.2fGb/%.2fGb", freeSpace, totalSpace);
    this->posCursor_X = 1;
    this->posCursor_Y += 2;

}

void ncurse::dispDateTime(IMonitorModule* module)
{
    Datetime *_module = static_cast<Datetime*>(module);
    Datetime dateInfo = *_module;
    dateInfo.refresh();
    std::string Time = dateInfo.getTime();
    std::string Date = dateInfo.getDate();
    mvwprintw(this->window, 1, this->_width - Date.size() - Time.size() - 2, "%s %s", Date.c_str(), Time.c_str());

}

void ncurse::dispSensors(IMonitorModule* module)
{
    Sensors *sensor = static_cast<Sensors*>(module);
    Sensors sensorInfo = *sensor;
    sensor->refresh();
    float tmp = sensorInfo.getTemperature();
    float tmpCrit = sensorInfo.getTemperatureCrit();
    mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, "GPU ° : %f° | Maximum allowed : %f°", tmp, tmpCrit);
    this->posCursor_Y += 1;
}

void ncurse::dispNetwork(IMonitorModule* module)
{
    Network *_network = static_cast<Network*>(module);
    Network &networkInfo = *_network;
    if (this->MbUp != 0) {
        this->MbUp = networkInfo.getUpNet();
        this->MbDown = networkInfo.getDownNet();
    } else {
        networkInfo.refresh();  
        this->MbUp = networkInfo.getUpNet();
        this->MbDown = networkInfo.getDownNet();
    }
    networkInfo.refresh();  
    this->MbUpDiff = (networkInfo.getUpNet() - this->MbUp);
    this->MbDownDiff = (networkInfo.getDownNet() - this->MbDown);
    mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, "NETWORK :");
    this->posCursor_Y += 1;
    mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, "    UP --> : %.6f Mb/s", this->MbUpDiff);
    this->posCursor_Y += 1;
    mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, "  DOWN --> : %.6f Mb/s", this->MbDownDiff);
    this->posCursor_Y += 1;    
}

int ncurse::dispPartBar(float memTotal, float memNode, float size, chtype color)
{
    float node = memTotal/size;
    int col = 1;
    while (node <= memNode) {
        node += memTotal/size;
        col += 1;
    }
    for (int i = 0; i < col; i++) {
        wattron(this->window, color);
        mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, " ");
        wattroff(this->window, color);
        this->posCursor_X += 1;
    }
    return col;
}

void ncurse::dispMemory(IMonitorModule* module)
{
    Memory *_module = static_cast<Memory*>(module);
    Memory memoryInfo = *_module;
    memoryInfo.refresh();
    float mem1 = memoryInfo.getMemoryAvailable();
    float mem2 = memoryInfo.getMemoryFree();
    float mem3 = memoryInfo.getMemoryTotal();
    float mem5 = memoryInfo.getSwapFree();
    float mem6 = memoryInfo.getSwapTotal();
    int size = 40;
    int colDisp = 1;
    int colFree = 1;
    int colOther = 1;
    this->posCursor_Y += 1;
    mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, "Memory      [");
    this->posCursor_X += 13;
    colFree = dispPartBar(mem3, mem2, size, COLOR_PAIR(3));
    colDisp = dispPartBar(mem3, mem1, size, COLOR_PAIR(4));
    colOther = size - colDisp - colFree;
    for (int i = 0; i < colOther; i++) {
        wattron(this->window, COLOR_PAIR(2));
        mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, " ");
        wattroff(this->window, COLOR_PAIR(2));
        this->posCursor_X += 1;
    }
    mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, "] %.2fG/%.2fG", mem3 - (mem1 + mem2), mem3);
    this->posCursor_X = 1;
    this->posCursor_Y += 2;
    mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, "Swap        [");
    this->posCursor_X += 13;
    colFree = dispPartBar(mem6, mem5, size, COLOR_PAIR(3));
    colOther = size - colFree;
    for (int i = 0; i < colOther; i++) {
        wattron(this->window, COLOR_PAIR(2));
        mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, " ");
        wattroff(this->window, COLOR_PAIR(2));
        this->posCursor_X += 1;
    }
    mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, "] %.2fG/%.2fG", mem6 - mem5, mem6);
    this->posCursor_X = 1;
    this->posCursor_Y += 2;
}

void ncurse::dispsysteminfo(IMonitorModule* module)
{
    SystemInfo *_module = static_cast<SystemInfo*>(module);
    SystemInfo info = *_module;
    info.refresh();
    std::string kernel = info.getKernel();
    std::string opSys = info.getOpSys();
    mvwprintw(this->window, this->_height - 2,this->_width - opSys.size() - kernel.size() - 4, "%s : %s", opSys.c_str(), kernel.c_str());
}

void ncurse::dispGPU(IMonitorModule* module)
{
    CpuInfo *_module = static_cast<CpuInfo*>(module);
    CpuInfo cpuInfo = *_module;
    cpuInfo.refresh();
    int coreNB = cpuInfo.getCoreNb();
    this->pourcent->refresh();
    float corePercent = this->pourcent->getCorePercent();
    std::string name = cpuInfo.getCPUModel();
    mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, "GPU : %s | %d coeurs", name.c_str(), coreNB);
    this->posCursor_Y += 2;
    mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, "1 :         [");
    this->posCursor_X += 13;
    int size = 40 * corePercent / 100;
    for (int i = 0; i < size; i++) {
        wattron(this->window, COLOR_PAIR(3));
        mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, " ");
        wattroff(this->window, COLOR_PAIR(3));
        this->posCursor_X += 1;
    }
    for (int i = 0; i < 40 - size; i++) {
        wattron(this->window, COLOR_PAIR(2));
        mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, " ");
        wattroff(this->window, COLOR_PAIR(2));
        this->posCursor_X += 1;
    }
    mvwprintw(this->window, this->posCursor_Y, this->posCursor_X, "] %d%%", (int)corePercent);
    this->posCursor_Y += 1;
    this->posCursor_X = 1;
    // printw("%s : %d\n", name.c_str(), coreNB);
    // printw("%s : %d\n", name.c_str(), coreNB);
}

void ncurse::displayModules(void)
{
    int type = 0;
    for (std::size_t i = 0; i < this->_modules.size(); i++) {
        if (this->_modules[i]->isActivated()) {
            type = this->_modules[i]->getModuleType();
            (this->*_functionModules[type])(this->_modules[i]);
        }
    }
    this->posCursor_Y = 3;
    this->posCursor_X = 1;
}

void ncurse::refreshModules(void)
{
    for (std::size_t i = 0; i < this->_modules.size(); i++)
        this->_modules[i]->refresh();
}

void ncurse::resetWindow(void)
{
    wclear(this->window);
    getmaxyx(this->window, this->_height, this->_width);
    this->window = newwin(this->_height, this->_width, 0, 0);
    start_color();
    nodelay(this->window, true);
    wclear(this->window);    
}

void ncurse::toggleModule(int type)
{
    for (std::size_t i = 0; i < this->_modules.size(); i++) {
        if (this->_modules[i]->getModuleType() == type)
            this->_modules[i]->switchModule();
    }
}

bool ncurse::handleKey(void)
{
    bool quit = false;
    int b = wgetch(this->window);
    switch (b) {
        case KEY_RESIZE:
            this->resetWindow();
            break;
        case 27:
            quit = true;
            break;
        case -1:
            break;
        case 97:
            toggleModule(0);
            resetWindow();
            break;
        case 122:
            toggleModule(1);
            resetWindow();
            break;
        case 101:
            toggleModule(2);
            resetWindow();
            break;
        case 114:
            toggleModule(3);
            resetWindow();
            break;
        case 116:
            toggleModule(4);
            resetWindow();
            break;
        case 121:
            toggleModule(5);
            resetWindow();
            break;
        case 117:
            toggleModule(6);
            resetWindow();
            break;
        case 105:
            toggleModule(7);
            resetWindow();
            break;
        case 111:
            toggleModule(8);
            resetWindow();
            break;
        case 112:
            toggleModule(9);
            resetWindow();
            break;
    }
    return quit;
}

void ncurse::run(void)
{
    initscr();
    getmaxyx(stdscr, this->_height, this->_width);
    this->window = newwin(this->_height, this->_width, 0, 0);
    nodelay(this->window, true);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_RED);
    init_pair(3, COLOR_GREEN, COLOR_GREEN);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    wbkgd(this->window, COLOR_PAIR(1));
    curs_set(0);
    keypad(this->window, true);
    noecho();
    while(1) {
        if (handleKey())
            break;
        displayModules();
        mvwhline(this->window, 2, 1, '-', this->_width);
        mvwhline(this->window, this->_height - 3, 1, '-', this->_width);
        box(this->window, 0, 0);
        wrefresh(this->window);
        napms(1000);
    }
    
    endwin();
}
