#ifndef OBJECT_MOVING
#define OBJECT_MOVING

#include "../main.h"
#include "object.h"

/// moving object
class moving : public object {
  public:
  void move(std::pair<int, int> xy);
  virtual void reset();

  protected:
  int state;
};
#endif
