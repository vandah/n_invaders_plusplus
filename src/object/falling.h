#ifndef OBJECT_MOVING_FALLING
#define OBJECT_MOVING_FALLING

#include "moving.h"

class falling : public moving {
  public:
  /// constructor, make 'down' the default direction for falling
  falling(bool down = true);

  /// default destructor
  ~falling();

  /// move up or down depending on the selected direction
  void fall();

  /// reset position to default
  void reset();

  /// draw the object
  virtual void redraw() const;

  protected:
  /// movement direction
  bool down;

  /// display available looks
  virtual std::vector<std::string> get_looks() const = 0;

  /// object's color
  virtual int color() const = 0;
};
#endif
