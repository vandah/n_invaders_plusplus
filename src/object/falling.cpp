#include "falling.h"

falling::falling(bool down)
    : down(down)
{
}

falling::~falling() {}

void falling::fall() { move({ 0, down ? -1 : 1 }); }
