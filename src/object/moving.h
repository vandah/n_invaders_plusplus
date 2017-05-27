#ifndef OBJECT_MOVING
#define OBJECT_MOVING

#include "object.h"

/// moving object
class moving : public object {
  public:
  void move(std::pair<int, int> xy);
  virtual void reset() = 0;

  protected:
  int state;
};
#endif
