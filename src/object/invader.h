#ifndef OBJECT_MOVING_INVADER
#define OBJECT_MOVING_INVADER

#include "moving.h"

class invader : public moving {
  public:
  void redraw();
  void destroy();
  void reset();
};
#endif
