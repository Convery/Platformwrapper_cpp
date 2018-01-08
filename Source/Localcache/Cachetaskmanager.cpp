/*
    Initial author: Convery (tcn@ayria.se)
    Started: 15-11-2017
    License: MIT
    Notes:
        Periodically runs tasks for the cache modules.
*/

#include "../Stdinclude.hpp"

namespace Localcache
{
    struct Task
    {
        std::chrono::steady_clock::time_point Lastcall;
        std::function<void()> Callback;
        uint32_t Delay;
    };
    std::vector<Task> Taskarray;

    // Add a task to the manager.
    void Addtask(std::function<void()> Callback, uint32_t Milliseconds)
    {
        Taskarray.push_back({ {}, Callback, Milliseconds });
    }

    // Start processing the tasks.
    void Runtasks()
    {
        auto Lambda = []() -> void
        {
            while (true)
            {
                auto Timestamp = std::chrono::steady_clock::now();

                for (auto &Item : Taskarray)
                {
                    if (Item.Delay > std::chrono::duration_cast<std::chrono::milliseconds>(Timestamp - Item.Lastcall).count())
                    {
                        Item.Lastcall = Timestamp;
                        Item.Callback();
                    }
                }

                std::this_thread::sleep_until(Timestamp + std::chrono::milliseconds(500));
            }
        };

    }
}
