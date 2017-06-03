#ifndef OBJECT
#define OBJECT

#include "../globals.h"

class player;
class invader;
class bunker;

#define FREE 0
#define INVADER_1 1
#define INVADER_2 2
#define INVADER_3 3
#define INVADER_4 4
#define UFO 5
#define INVADER_MISSILE 6
#define BUNKER 7
#define PLAYER_MISSILE 8
#define PLAYER 9

/// generic static object
class object {
  public:
  object();

  virtual ~object();

  /// show the object
  virtual void redraw() const;

  /// delete pointers pointing to the object
  virtual void destroy();

  void reset();

  std::pair<int, int> pos;

  std::string current_look() const;

  protected:
  virtual int color() const = 0;

  /// switch look
  void next_look();

  /// get an array of available looks
  virtual std::vector<std::string> get_looks() const = 0;

  /// which look shoould be displayed
  int choice;

  std::pair<int, int> size;
};
#endif
