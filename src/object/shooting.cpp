#include "shooting.h"

void shooting::reset() {}
void shooting::redraw() const { moving::redraw(); }
void shooting::missile::set_pos(std::pair<int, int> new_pos) { pos = new_pos; }
