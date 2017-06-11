#ifndef OBJECT_MOVING_SHOOTING_INVADER
#define OBJECT_MOVING_SHOOTING_INVADER

#include "shooting.h"

#define INVADER_1 1
#define INVADER_2 2
#define INVADER_3 3
#define INVADER_4 4
#define UFO 5

class invader : public shooting {
  public:
  /// constructor, needs to specify the type of an invader
  invader(int type);

  /// default destructor
  ~invader();

  /// reset position to default
  void reset();

  /// delete pointers to prevent segfault
  void destroy();

  /// get available looks
  std::vector<std::string> get_looks() const;

  /// object's color
  int color() const;

  /// points received after destruction
  int points() const;

  /// draw the object again
  void redraw() const;

  /// shoot a missile and let it fall
  void shoot();

  class missile : public missile_base {
public:
    /// default constructor
    missile();

    /// default destructor
    ~missile();

    /// delete pointers to prevent segfault
    void destroy();

    /// default position
    std::pair<int, int> init_pos;

protected:
    /// available looks
    std::vector<std::string> get_looks() const;

    /// missile color
    int color() const;
  };

  protected:
  /// invader type - different looks and score
  int type;
};
#endif
