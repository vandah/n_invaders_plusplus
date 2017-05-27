#ifndef OBJECT_MOVING_FALLING_BONUS
#define OBJECT_MOVING_FALLING_BONUS

#include "../falling.h"

class bonus : public falling {
  public:
  virtual void grant();
  void redraw();
  void destroy();
};
#endif

