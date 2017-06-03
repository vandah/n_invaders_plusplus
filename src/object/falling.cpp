#include "falling.h"

falling::falling(bool down)
    : down(down)
{
}

falling::~falling() {}

void falling::fall() { move({ down ? 1 : -1, 0 }); }

void falling::reset() {}

void falling::redraw() const { moving::redraw(); }
