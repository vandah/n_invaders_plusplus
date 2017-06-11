#ifndef OBJECT_MOVING_SHOOTING_INVADER
#define OBJECT_MOVING_SHOOTING_INVADER

#include "shooting.h"

class invader : public shooting {
  public:
  invader(int type);

  ~invader();

  void reset();

  void destroy();

  std::vector<std::string> get_looks() const;

  int color() const;

  int points() const;

  void redraw() const;

  void shoot();

  class missile : public missile_base {
public:
    missile();
    ~missile();
    void destroy();
    std::pair<int,int> init_pos;

protected:
    std::vector<std::string> get_looks() const;
    int color() const;
  };

  protected:
  int type;
};
#endif
