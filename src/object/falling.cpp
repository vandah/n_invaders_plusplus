#include "falling.h"

void falling::fall(bool down) { move({ 0, down ? -1 : 1 }); }

void falling::reset() {}
