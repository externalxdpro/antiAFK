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
        LPSTR windowTitle_lpstr;
        GetWindowText(GetForegroundWindow(), windowTitle_str, MAXINT32);
        string windowTitle_str = windowTitle_lpstr;

        int notepadLength = 7;
        int geforceLength = 11;

        if (windowTitle_str.substr(size(windowTitle_str) - notepadLength) == "Notepad" || windowTitle_str.substr(size(windowTitle_str) - geforceLength) == "GeForce Now")
        {
            int minVal = 0x41;
            int maxVal = 0x5A;

            srand(time(nullptr));
            int randKey = rand() % (maxVal - minVal + 1) + minVal;
            keybd_event(randKey, 0, 0, 0);
            sleep_for(milliseconds(10));
            keybd_event(VK_BACK, 0, 0, 0);
        }
    }

    return 0;
}