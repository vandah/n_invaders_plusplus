#ifndef SCR_INSTRUCTIONS
#define SCR_INSTRUCTIONS

#include "scr_list.h"

/// game instructions
class scr_instructions : public scr_list {
  public:
  /// default constructor
  scr_instructions();

  /// default destructor
  ~scr_instructions();

  /// draw the screen again
  void redraw() const;

  /// print game instructions
  void draw_instructions() const;

  private:
  /// groups title with content
  class lines {
public:
    /// default constructor
    lines();

    /// constructor taking arguments - for usage with initializer lists
    lines(std::string title, std::vector<std::string> arr);

    /// title of the text
    std::string title;

    /// content of the paragraph
    std::vector<std::string> content;
  };

  /// returns instructions in a screen-printable form
  std::vector<lines> get_instructions() const;
};

#endif
