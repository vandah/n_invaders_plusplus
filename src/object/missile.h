#ifndef OBJECT_MOVING_FALLING_MISSILE
#define OBJECT_MOVING_FALLING_MISSILE

#include "falling.h"

class missile : public falling {
  public:
  missile(bool invader = false);

  ~missile();

  protected:
  int color() const;

  std::vector<std::string> get_looks() const;
};
#endif
