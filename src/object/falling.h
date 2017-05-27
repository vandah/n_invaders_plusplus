#ifndef OBJECT_MOVING_FALLING
#define OBJECT_MOVING_FALLING

#include "moving.h"

class falling : public moving {
  public:
  void fall(bool down = true);
  void reset();
};
#endif
