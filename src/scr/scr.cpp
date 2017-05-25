#include "scr.h"
#include "../main.h"

scr::scr()
    : state(0)
    , win(NULL)
    , midcol(0)
    , midrow(0)
{
}

scr::~scr() { endwin(); }
