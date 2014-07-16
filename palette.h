#ifndef PALETTE_H
#define PALETTE_H

#include "table.hpp"
#include "table.ipp"

#include "exitCodes.h"
#include "colorTools.h"

#define PALETTE_MAX_NAME 50

#ifdef QT_DEBUG
#include <iostream>
#endif

class Palette : public table<int4>
{
private:
    char name[PALETTE_MAX_NAME];

public:
    Palette();

    void getName(char* name_);
    void setName(char* name_);

    unsigned long getMergedAt(int i);
};

#endif
