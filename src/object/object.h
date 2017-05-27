#ifndef OBJECT
#define OBJECT

#include "../globals.h"

/// generic static object
class object {
  public:
  object(int size_x = 0, int size_y = 0, int pos_x = 0, int pos_y = 0);
  virtual ~object();
  void redraw();
  virtual void destroy() = 0;

  protected:
  class TLook {
public:
    TLook();
    ~TLook();
    void fill_wardrobe();
    std::string current_look();
    void next_look();
    void reset();

private:
    std::vector<std::string> wardrobe;
    int choice;
  };

  TLook show;
  TLook destroy_effect;

  std::pair<int, int> size;
  std::pair<int, int> pos;
};
#endif
