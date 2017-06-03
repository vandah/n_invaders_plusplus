#ifndef OBJECT_MOVING
#define OBJECT_MOVING

#include "object.h"

/// moving object
class moving : public object {
  public:
  moving();
  ~moving();
  void move(std::pair<int, int> xy);

  bool top();
  bool bottom();
  bool right();
  bool left();

  virtual void reset() = 0;

  virtual void redraw() const;

  protected:
  virtual int color() const = 0;
  virtual std::vector<std::string> get_looks() const = 0;
  std::pair<int, int> old_pos;
};
#endif
