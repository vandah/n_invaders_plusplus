#ifndef OBJECT_MOVING
#define OBJECT_MOVING

#include "../main.h"
#include "object.h"

/// moving object
class moving : public object {
  public:
  void move(std::pair<int, int> xy);

  virtual void reset() = 0;

  using object::redraw;

  virtual std::vector<std::string> get_looks() const = 0;

  protected:
  virtual int color() const = 0;
};
#endif
