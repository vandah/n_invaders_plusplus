#include "screen_base.h"
#include "../main.h"

screen_base::screen_base()
    : state(0)
    , win(NULL)
    , midcol(0)
    , midrow(0)
{
}

screen_base::~screen_base() { endwin(); }
