//
// Created by tlylz on 2019/10/7.
//

#ifndef RICHERS_MAPMGR_H
#define RICHERS_MAPMGR_H

#include "global.h"
#include "mapbuilder.h"
#include "map.h"

class MapMgr
{
public:
    static MapMgr* getMgr();
    static void      releaseMgr();
private:
    static MapMgr* mgr;
private:
    MapMgr();
    MapMgr(const MapMgr&);
    MapMgr& operator=(const MapMgr&);
public:
    Map * getCurMap() { return curMap;}
    void createMap();
    ~MapMgr();
private:
    Map* curMap = nullptr;
};

#endif //RICHERS_MAPMGR_H
