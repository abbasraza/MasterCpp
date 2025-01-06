#include <iostream>
#include <map>
#include <thread>
#include <mutex>
std::map<int, int> myMap;
        std::mutex mtx;


void runThread(int key, int value)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    //mtx.lock();

    for (auto it = myMap.cbegin(); it != myMap.cend();)
    {
        std::map<int, int>::iterator tmp = myMap.find(it->first);
        tmp->second++;
        if (tmp->second > 2)
        {
            myMap.erase(it++); // or "it = m.erase(it)" since C++11
        }
        else
        {
            ++it;
        }
    }
    //mtx.unlock();

}

void updateElem(int key, int value)
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        mtx.lock();
        for (auto &it : myMap)
        {
            it.second++;
        }

        for (const auto &pair : myMap)
        {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
        mtx.unlock();
    }
}

int main()
{
    myMap.insert({1, 10});
    // myMap.insert({2, 20});
    // myMap.insert({3, 30});

    std::thread t1(updateElem, 2, 200);
    std::thread t2(runThread, 3, 300);

    t1.join();
    t2.join();


    return 0;
}