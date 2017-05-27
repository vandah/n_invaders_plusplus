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
#endif
