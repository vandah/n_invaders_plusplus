#ifndef OBJECT_MOVING_FALLING_MISSILE
#define OBJECT_MOVING_FALLING_MISSILE

#include "falling.h"

class missile : public falling {
  public:
  missile(bool invader = false);
  ~missile();
};
#endif
