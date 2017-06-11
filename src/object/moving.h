#ifndef OBJECT_MOVING
#define OBJECT_MOVING

#include "object.h"

/// moving object
class moving : public object {
  public:
  /// default constructor
  moving();

  /// default destructor
  ~moving();

  /// the main function for this class - move to a relative position
  void move(std::pair<int, int> yx);

  /// have the object reached the top?
  bool top();

  /// have the object reached the bottom?
  bool bottom();

  /// have the object reached the right side?
  bool right();

  /// have the object reached the left side?
  bool left();

  /// reset to default position
  virtual void reset() = 0;

  /// draw the object again
  virtual void redraw() const;

  protected:
  /// object's color
  virtual int color() const = 0;

  /// available looks
  virtual std::vector<std::string> get_looks() const = 0;

  /// position before the last move
  std::pair<int, int> old_pos;
};
#endif
