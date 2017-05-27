#include "player.h"
player::player() { reset(); }

player::~player() {}

void player::reset() { pos = { gui.cols / 2, gui.rows / 2 }; }
