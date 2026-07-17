#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <string>

using namespace std;

class ConsoleUI
{
public:
    static void reset();

    static void red();
    static void green();
    static void yellow();
    static void blue();
    static void cyan();
    static void magenta();

    static void success(string message);
    static void error(string message);
    static void warning(string message);
    static void heading(string message);
};

#endif
