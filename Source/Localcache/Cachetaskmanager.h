/*
    Initial author: Convery (tcn@ayria.se)
    Started: 15-11-2017
    License: MIT
    Notes:
        Periodically runs tasks for the cache modules.
*/

#pragma once
#include "../Stdinclude.hpp"

namespace Localcache
{
    // Add a task to the manager.
    void Addtask(std::function<void()> Callback, uint32_t Milliseconds);

    // Start processing the tasks.
    void Runtasks();
}
