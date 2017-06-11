#ifndef SCR_INSTRUCTIONS
#define SCR_INSTRUCTIONS

#include "scr_list.h"

/// game instructions
class scr_instructions : public scr_list {
  public:
  scr_instructions();

  ~scr_instructions();

  void redraw() const;

  void draw_instructions() const;

  private:
  class lines {
public:
    lines();

    lines(std::string title, std::vector<std::string> arr);

    std::string title;

    std::vector<std::string> content;
  };

  std::vector<lines> get_instructions() const;
};

#endif
