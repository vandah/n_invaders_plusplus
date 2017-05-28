#ifndef OBJECT_MOVING_FALLING
#define OBJECT_MOVING_FALLING

#include "moving.h"

class falling : public moving {
  public:
  /// constructor, make 'down' the default direction for falling
  falling(bool down = true);

  ~falling();

  /// move up or down depending on the selected direction
  void fall();

  void reset();

  protected:
  /// movement direction
  bool down;

  virtual std::vector<std::string> get_looks() const = 0;

  virtual int color() const = 0;
};
#endif
