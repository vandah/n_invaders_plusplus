#ifndef OBJECT
#define OBJECT

#include "../globals.h"

/// generic static object
class object {
  public:
  object(int size_x = 0, int size_y = 0, int pos_x = 0, int pos_y = 0);

  virtual ~object();

  /// show the object
  virtual void redraw() const;

  virtual void destroy();

  void reset();

  protected:
  virtual int color() const = 0;

  std::string current_look() const;

  /// switch look
  void next_look();

  /// get an array of available looks
  virtual std::vector<std::string> get_looks() const = 0;

  /// which look shoould be displayed
  int choice;

  std::pair<int, int> size;

  std::pair<int, int> pos;
};
#endif
