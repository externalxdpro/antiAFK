#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    while (true)
    {
        keybd_event(0x45, 0, 0, 0);
        Sleep(1000);
    }

    return 0;
}