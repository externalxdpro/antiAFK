#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <vector>
#include <windows.h>

using namespace std;
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

bool checkWindowTitle(string fileName)
{
    char temp[256];
    GetWindowText(GetForegroundWindow(), temp, size(temp));
    string title = temp;
    
    string line;
    ifstream iFileHandler(fileName);
    getline(iFileHandler, line);

    if (line.size() == 0) return true;

    vector<string> list = split(line, ',');

    for (string program : list)
    {
        if (size(title) >= size(program) && title.substr(size(title) - size(program)) == program)
        {
            return true;
            this_thread::sleep_for(seconds(1));
        }
    }

    return false;
}

void randomKeys(string fileName)
{
    int minVal = 0x41;
    int maxVal = 0x5A;
    seconds delay = seconds(1);

    for (int i = 3; i >= 1; i--)
    {
        cout << "Starting in " << i << endl;
        this_thread::sleep_for(seconds(1));
    }
    cout << "Press 'CTRL + C' to end the program.";

    while (true)
    {
        if (!checkWindowTitle(fileName))
        {
            this_thread::sleep_for(delay);
            continue;
        }

        srand(time(nullptr));
        int randKey = rand() % (maxVal - minVal + 1) + minVal;
        keybd_event(randKey, 0, 0, 0);
        this_thread::sleep_for(delay);
        keybd_event(randKey, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(VK_BACK, 0, 0, 0);
        this_thread::sleep_for(delay);
        keybd_event(VK_BACK, 0, KEYEVENTF_KEYUP, 0);
    }
}

void randomMovementWASD(string fileName)
{
    int keys[] = {0x57, 0x41, 0x53, 0x44};
    int maxVal = size(keys);
    seconds delay = seconds(1);

    for (int i = 3; i >= 1; i--)
    {
        cout << "Starting in " << i << endl;
        this_thread::sleep_for(seconds(1));
    }
    cout << "Press 'CTRL + C' to end the program.";

    while (true)
    {
        if (!checkWindowTitle(fileName))
        {
            this_thread::sleep_for(delay);
            continue;
        }

        srand(time(nullptr));
        int randKey = keys[rand() % maxVal];
        keybd_event(randKey, 0, 0, 0);
        this_thread::sleep_for(delay);
        keybd_event(randKey, 0, KEYEVENTF_KEYUP, 0);
    }
}

void randomMovementArrows(string fileName)
{
    int keys[] = {VK_UP, VK_LEFT, VK_DOWN, VK_RIGHT};
    int maxVal = size(keys);
    seconds delay = seconds(1);

    for (int i = 3; i >= 1; i--)
    {
        cout << "Starting in " << i << endl;
        this_thread::sleep_for(seconds(1));
    }
    cout << "Press 'CTRL + C' to end the program.";

    while (true)
    {
        if (!checkWindowTitle(fileName))
        {
            this_thread::sleep_for(delay);
            continue;
        }

        srand(time(nullptr));
        int randKey = keys[rand() % maxVal];
        keybd_event(randKey, 0, 0, 0);
        this_thread::sleep_for(delay);
        keybd_event(randKey, 0, KEYEVENTF_KEYUP, 0);
    }
}

void editProgramsList(string fileName)
{
    ifstream iFileHandler;
    ofstream oFileHandler;
    string line;
    
    iFileHandler.open(fileName);
    getline(iFileHandler, line);
    iFileHandler.close();

    cout << "Current list: " << line << endl;
    cout << "Enter new list: ";

    string input;
    getline(cin, input);

    oFileHandler.open(fileName);
    oFileHandler << input;
    oFileHandler.close();

    cout << "Program list updated." << endl;
    this_thread::sleep_for(seconds(1));
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
         << "4: Edit program list" << endl
         << "5: Exit" << endl;
    getline(cin, input);
    
    try
    {
        choice = stoi(input);
    }
    catch(const std::invalid_argument exception)
    {
        cout << "Enter one of the options." << endl;
        this_thread::sleep_for(seconds(1));
        main();
    }

    string fileName = "list";

    switch (choice)
    {
    case 1:
        randomKeys(fileName);
        break;

    case 2:
        randomMovementWASD(fileName);
        break;
    
    case 3:
        randomMovementArrows(fileName);
        break;

    case 4:
        editProgramsList(fileName);
        main();
        break;
    
    case 5:
        return 0;
    
    default:
        cout << "Enter one of the options." << endl;
        this_thread::sleep_for(seconds(1));
        main();
    }
}