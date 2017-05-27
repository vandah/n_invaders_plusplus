#ifndef OBJECT_MOVING_FALLING_SMART
#define OBJECT_MOVING_FALLING_SMART

#include "falling.h"

class smart : public moving {
  public:
  void redraw();
  void destroy();
};
#endif
