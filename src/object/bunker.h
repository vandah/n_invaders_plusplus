#ifndef OBJECT_BUNKER
#define OBJECT_BUNKER

#include "object.h"

class bunker : public object {
  public:
  /// default constructor
  bunker();

  /// default destructor
  ~bunker();

  /// remove pointers to prevent segfault (used before delete)
  void destroy();

  protected:
  /// display available looks
  std::vector<std::string> get_looks() const;

  /// object color
  int color() const;
};
#endif
