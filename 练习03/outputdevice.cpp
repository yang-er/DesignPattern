//
// Created by tlylz on 2019/10/9.
//

#include "outputdevice.h"

StreamDevice::~StreamDevice() = default;
PrinterDevice::~PrinterDevice() = default;
WindowDevice::~WindowDevice() = default;
void PrinterDevice::draw(const char *pstr) { }
void WindowDevice::draw(const char *pstr) { }
void PrinterDevice::drawLn(const char *pstr) { }
void WindowDevice::drawLn(const char *pstr) { }

devstream &endl(devstream &left)
{
    left->drawLn("");
    return left;
}

devstream &operator<<(devstream &left, const char *str)
{
    left->draw(str);
    return left;
}

devstream &operator<<(devstream &left, int val)
{
    static char buf[100];
    sprintf(buf, "%d", val);
    left->draw(buf);
    return left;
}

devstream &operator<<(devstream &left, const std::function<devstream&(devstream&)> &func)
{
    return func(left);
}

void StreamDevice::draw(const char *pstr)
{
    for (int i = 0; pstr[i]; i++) drawCh(pstr[i]);
}

void StreamDevice::drawLn(const char *pstr)
{
    draw(pstr); drawCh('\n');
}

void StreamDevice::drawCh(char ch)
{
    putchar(ch);
}

