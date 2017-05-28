#ifndef OBJECT_MOVING
#define OBJECT_MOVING

#include "../main.h"
#include "object.h"

/// moving object
class moving : public object {
  public:
  void move(std::pair<int, int> xy);
  
  bool top();
  bool bottom();
  bool right();
  bool left();

  virtual void reset() = 0;

  using object::redraw;

  protected:
  virtual int color() const = 0;
  virtual std::vector<std::string> get_looks() const = 0;
};
#endif
