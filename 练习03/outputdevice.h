//
// Created by tlylz on 2019/10/9.
//

#ifndef RICHERS_OUTPUTDEVICE_H
#define RICHERS_OUTPUTDEVICE_H
#include <memory>
#include <functional>

class OutputDevice {
public:
    virtual void draw(const char *pstr) = 0;
    virtual void drawLn(const char *pstr) = 0;
    virtual ~OutputDevice() = default;

protected:
    OutputDevice() = default;
};

class StreamDevice : public OutputDevice {
public:
    virtual void draw(const char *pstr);
    virtual void drawLn(const char *pstr);
    virtual void drawCh(char ch);
    virtual ~StreamDevice();
};

class PrinterDevice : public OutputDevice {
public:
    virtual void draw(const char *pstr);
    virtual void drawLn(const char *pstr);
    virtual ~PrinterDevice();
};

class WindowDevice : public OutputDevice {
public:
    virtual void draw(const char *pstr);
    virtual void drawLn(const char *pstr);
    virtual ~WindowDevice();
};

typedef std::shared_ptr<OutputDevice> devstream;
devstream &endl(devstream &left);
devstream &operator<<(devstream &left, const char *str);
devstream &operator<<(devstream &left, int val);
devstream &operator<<(devstream &left, const std::function<devstream&(devstream&)> &func);

#endif //RICHERS_OUTPUTDEVICE_H
