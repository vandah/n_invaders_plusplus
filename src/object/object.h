#ifndef OBJECT
#define OBJECT

#include "../globals.h"

/// generic static object
class object {
  public:
  object(int sx = 0, int sy = 0, int px = 0, int py = 0);
  virtual ~object();
  virtual void redraw() = 0;
  virtual void destroy() = 0;

  protected:
  struct TLook {
    std::vector<std::string> wardrobe;
    int choice;
  };

  TLook show;
  TLook destroy_effect;

  std::pair<int, int> size;
  std::pair<int, int> pos;
};

/// moving object
class moving : public object {
  public:
  void move(std::pair<int, int> xy);
  virtual void reset() = 0;

  protected:
  int state;
};

class falling : public moving {
  public:
  void fall(bool down = true);
  void redraw();
  void destroy();
  void reset();
};

class missile : public falling {
  public:
  void redraw();
  void destroy();
};

class bonus : public falling {
  public:
  virtual void grant();
  void redraw();
  void destroy();
};

class smart : public moving {
  public:
  void redraw();
  void destroy();
};

class invader : public moving {
  public:
  void redraw();
  void destroy();
  void reset();
};

class ufo : public moving {
  public:
  void redraw();
  void destroy();
  void reset();
};

class player : public moving {
  public:
  void redraw();
  void destroy();
  void reset();
};
#endif
