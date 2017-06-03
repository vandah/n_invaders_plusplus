#ifndef OBJECT_MOVING_INVADER
#define OBJECT_MOVING_INVADER

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

  class missile : public missile_base {
public:
    missile();
    ~missile();

protected:
    std::vector<std::string> get_looks() const;
    int color() const;
  };

  std::vector<missile*> missiles;
  missile* active_missile;

  protected:
  int type;
};
#endif
