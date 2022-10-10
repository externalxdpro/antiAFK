#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>

using namespace std;
using namespace this_thread;
using namespace chrono;

void RandomKeys()
{
    int minVal = 0x41;
    int maxVal = 0x5A;
    seconds delay = seconds(1);

    for (int i = 3; i >= 1; i--)
    {
        cout << "Starting in " << i << endl;
        sleep_for(seconds(1));
    }
    cout << "Press 'CTRL + C' to end the program.";

    while (true)
    {
        srand(time(nullptr));
        int randKey = rand() % (maxVal - minVal + 1) + minVal;
        keybd_event(randKey, 0, 0, 0);
        sleep_for(delay);
        keybd_event(randKey, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(VK_BACK, 0, 0, 0);
        sleep_for(delay);
        keybd_event(VK_BACK, 0, KEYEVENTF_KEYUP, 0);
    }
}

void RandomMovementWASD()
{
    int keys[] = {0x57, 0x41, 0x53, 0x44};
    int maxVal = size(keys);
    seconds delay = seconds(1);

    for (int i = 3; i >= 1; i--)
    {
        cout << "Starting in " << i << endl;
        sleep_for(seconds(1));
    }
    cout << "Press 'CTRL + C' to end the program.";

    while (true)
    {
        srand(time(nullptr));
        int randKey = keys[rand() % maxVal];
        keybd_event(randKey, 0, 0, 0);
        sleep_for(delay);
        keybd_event(randKey, 0, KEYEVENTF_KEYUP, 0);
    }
}

void RandomMovementArrows()
{
    int keys[] = {VK_UP, VK_LEFT, VK_DOWN, VK_RIGHT};
    int maxVal = size(keys);
    seconds delay = seconds(1);

    for (int i = 3; i >= 1; i--)
    {
        cout << "Starting in " << i << endl;
        sleep_for(seconds(1));
    }
    cout << "Press 'CTRL + C' to end the program.";

    while (true)
    {
        srand(time(nullptr));
        int randKey = keys[rand() % maxVal];
        keybd_event(randKey, 0, 0, 0);
        sleep_for(delay);
        keybd_event(randKey, 0, KEYEVENTF_KEYUP, 0);
    }
}

int main()
{
    int choice;
    
    // Choice selection
    cout << "Enter a number:" << endl
         << "1: Random Keys (typically for main menus)" << endl
         << "2: Random WASD Movement (typically for in-game)" << endl
         << "3: Random Arrow Key Movement (typically for in-game)" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        RandomKeys();
        break;

    case 2:
        RandomMovementWASD();
        break;
    
    case 3:
        RandomMovementArrows();
        break;
    
    default:
        cout << "Enter one of the options." << endl;
        main();
    }

    return 0;
}