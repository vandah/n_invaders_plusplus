#ifndef OBJECT_BUNKER
#define OBJECT_BUNKER

#include "object.h"

class bunker : public object {
  public:
  bunker();

  ~bunker();

  protected:
  std::vector<std::string> get_looks() const;

  int color() const;
};
#endif
