#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>

using namespace std;
using namespace this_thread;
using namespace chrono;

int main()
{
    while (true)
    {
        int minVal = 0x41;
        int maxVal = 0x5A;

        for (int i = 0; i < 26; i++)
        {
            srand(time(nullptr));
            int randKey = rand() % (maxVal - minVal + 1) + minVal;
            keybd_event(randKey, 0, 0, 0);
            sleep_for(seconds(1));
        }

        for (int i = 0; i < 26; i++)
        {
            keybd_event(VK_BACK, 0, 0, 0);
            sleep_for(milliseconds(100));
        }
    }

    return 0;
}