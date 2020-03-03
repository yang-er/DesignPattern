#include <iostream>
#include "game.h"
#include <memory>
#include "outputdevice.h"
#include "menu.h"
using namespace std;

class TabbedStreamDevice : public OutputDevice {
public:
    TabbedStreamDevice(StreamDevice *in) : inner(in) {}
    StreamDevice *inner;
    virtual void draw(const char *pstr) { inner->draw(pstr); }
    virtual void drawLn(const char *pstr) { inner->drawLn(pstr); inner->drawCh('\t'); }
    virtual ~TabbedStreamDevice() { delete inner; }
};

std::shared_ptr<OutputDevice> Menu::dev(new StreamDevice);

int main()
{
    Game *t = Game::getGame();
    t->init();
    t->run();
    t->term();
    t->releaseGame();
    return 0;
}
