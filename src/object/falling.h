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

  protected:
  /// movement direction
  bool down;
};
#endif
