#ifndef OBJECT_MOVING_SHOOTING
#define OBJECT_MOVING_SHOOTING

#include "falling.h"

class shooting : public moving {
  public:
  /// reset to default position
  virtual void reset() = 0;

  //  virtual void redraw() const;
  using moving::redraw;

  /// add new missile and let it fly
  virtual void shoot() = 0;

  class missile_base : public falling {
public:
    /// default constructor
    missile_base();

    /// virtaul destructor
    virtual ~missile_base();

    /// set absolute position
    void set_pos(std::pair<int, int> new_pos);

    /// delete pointers to prevent segfault - cleanup
    void destroy();

protected:
    /// get available looks
    virtual std::vector<std::string> get_looks() const = 0;

    /// get object's color
    virtual int color() const = 0;
  };

  protected:
  /// get available looks
  virtual std::vector<std::string> get_looks() const = 0;

  /// get object's color
  virtual int color() const = 0;
};
#endif
