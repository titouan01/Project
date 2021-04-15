// /*
// ** EPITECH PROJECT, 2021
// ** B-CPP-300-MPL-3-1-CPPrush3-louis.boulet
// ** File description:
// ** CpuPourcent
// */

#include "CpuPourcent.hpp"

void CpuPourcent::defineCorePercent(float corePercent) { this->_useCPU = corePercent; }
float CpuPourcent::getCorePercent() const { return (this->_useCPU); }

CpuPourcent::CpuPourcent()
{
    this->_isEnabled = true;
    this->_moduleType = CPU;
    this->_useCPU = 0.0;
}

std::vector<size_t> get_cpu_times()
{
    std::ifstream proc_stat("/proc/stat");
    proc_stat.ignore(5, ' '); // Skip the 'cpu' prefix.
    std::vector<size_t> times;
    for (size_t time; proc_stat >> time; times.push_back(time))
        ;
    return times;
}

bool get_cpu_times(size_t &idle_time, size_t &total_time)
{
    const std::vector<size_t> cpu_times = get_cpu_times();
    if (cpu_times.size() < 4)
        return false;
    idle_time = cpu_times[3];
    total_time = std::accumulate(cpu_times.begin(), cpu_times.end(), 0);
    return true;
}

void CpuPourcent::refresh(void)
{
    size_t idle_time, total_time;
    get_cpu_times(idle_time, total_time);
    const float idle_time_delta = idle_time - this->previous_idle_time;
    const float total_time_delta = total_time - this->previous_total_time;
    this->previous_idle_time = idle_time;
    this->previous_total_time = total_time;
    const float utilization = 100.0 * (1.0 - idle_time_delta / total_time_delta);
    defineCorePercent(utilization);
}

void CpuPourcent::switchModule(void)
{
    this->_isEnabled = !this->_isEnabled;
}

CpuPourcent::~CpuPourcent()
{
}
