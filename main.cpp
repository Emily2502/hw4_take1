#include <iostream>
#include <fstream>
#include "Queue.h"

using std::cout;
using std::ifstream;
using std::string;
using std::endl;

void readNamesOfCards(const char* sourceFileName, Queue<string>& queue);

int main()
{
    Queue<string> queue;
    readNamesOfCards("../text.txt", queue);
    for (const string& name : queue)
    {
        cout << name << endl;
    }
    return 0;
}


void readNamesOfCards(const char* sourceFileName, Queue<string>& queue)
{
    ifstream source(sourceFileName);
    if (!source)
    {
        //Exceptions
        return;
    }
    string name;
    char buffer;

    while (!source.eof())
    {
        source.get(buffer);

        if (buffer != '\n')
        {
            name += buffer;
        }
        else if (!name.empty())
        {
            queue.pushBack(name);
            name = "";
        }
    }
    queue.pushBack(name);
}