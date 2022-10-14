#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <vector>
#include <windows.h>

using namespace std;
using namespace this_thread;
using namespace chrono;

vector<string> split(string s, char delimiter = ' ')
{
    int current;
    int next = -1;

    vector<string> result;

    do
    {
        current = next + 1;
        next = s.find_first_of(delimiter, current);
        result.push_back(s.substr(current, next - current));
    } while (next != string::npos);

    return result;
}

void printVector(vector<string> list)
{
    for (int i = 0; i < size(list); i++)
    {
        if (i == size(list) - 1)
        {
            cout << list[i] << endl;
        }
        else
        {
            cout << list[i] << ",";
        }
    }
}

void randomKeys()
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

void randomMovementWASD()
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

void randomMovementArrows()
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

void editProgramsList()
{
    ifstream iFileHandler;
    ofstream oFileHandler;
    string file = "list";
    string line;
    
    iFileHandler.open(file);
    getline(iFileHandler, line);
    iFileHandler.close();

    cout << "Current list: " << line << endl;
    cout << "Enter new list: ";

    string input;
    getline(cin, input);

    oFileHandler.open(file);
    oFileHandler << input;
    oFileHandler.close();

    cout << "Program list updated." << endl;
    sleep_for(seconds(1));
}

void testForegroundWindow()
{
    while (true)
    {
        char temp[256];
        GetWindowText(GetForegroundWindow(), temp, size(temp));
        string title = temp;

        int notepadLength = 7;

        try
        {
            if (title.substr(size(title) - notepadLength) == "Notepad")
            {
                cout << title.substr(size(title) - notepadLength) << endl;
                sleep_for(seconds(1));
            }
        }
        catch(const std::out_of_range &exception)
        {
            cout << "Out of range" << endl;
            sleep_for(seconds(1));
        }
    }
}

int main()
{
    // Choice selection
    string input;
    int choice;

    cout << "Enter a number:" << endl
         << "1: Random Keys (typically for main menus)" << endl
         << "2: Random WASD Movement (typically for in-game)" << endl
         << "3: Random Arrow Key Movement (typically for in-game)" << endl
         << "4: Edit program list" << endl;
    getline(cin, input);
    
    try
    {
        choice = stoi(input);
    }
    catch(const std::invalid_argument exception)
    {
        cout << "Enter one of the options." << endl;
        sleep_for(seconds(1));
        main();
    }

    switch (choice)
    {
    case 1:
        randomKeys();
        break;

    case 2:
        randomMovementWASD();
        break;
    
    case 3:
        randomMovementArrows();
        break;

    case 4:
        editProgramsList();
        main();
        break;
    
    case 5:
        testForegroundWindow();
        break;
    
    default:
        cout << "Enter one of the options." << endl;
        sleep_for(seconds(1));
        main();
    }

    return 0;
}