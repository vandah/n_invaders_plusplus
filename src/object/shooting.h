#ifndef OBJECT_MOVING_SHOOTING
#define OBJECT_MOVING_SHOOTING

#include "falling.h"
#include "moving.h"

class shooting : public moving {
  public:
  virtual void reset() = 0;

  virtual std::vector<std::string> get_looks() const = 0;

  virtual void redraw() const;

  //  class missile;
  class missile : falling {
public:
    missile();
    ~missile();
    void redraw() const;
    void set_pos(std::pair<int, int> new_pos);

protected:
    std::vector<std::string> get_looks() const;
    int color() const;
  };

  protected:
  virtual int color() const = 0;
};
#endif
