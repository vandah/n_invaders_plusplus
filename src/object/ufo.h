#ifndef OBJECT_MOVING_UFO
#define OBJECT_MOVING_UFO

#include "moving.h"

class ufo : public moving {
  public:
  void redraw();
  void destroy();
  void reset();
};
#endif
