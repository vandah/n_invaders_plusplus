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

  static int score;

  static int level;

  static int lives;

  protected:
  virtual int color() const = 0;

  /// switch look
  void next_look();

  /// get an array of available looks
  virtual std::vector<std::string> get_looks() const = 0;

  /// which look should be displayed
  int choice;

  static std::pair<int, int> size;

  static std::vector<std::vector<object*>> battlefield;

  static player* Player;

  template <typename _T> class grid {
public:
    grid()
        : right(true)
    {
    }

    ~grid() { clear(); }

    std::pair<int, int> pos;

    bool empty() { return !cnt; }

    unsigned int size() { return arr.size(); }

    void clear()
    {
      for (unsigned int i = 0; i < arr.size(); ++i) {
        arr[i].clear();
      }
      arr.clear();
    }

    void move()
    {
      for (unsigned int i = 0; i < arr.size(); ++i) {
        if (right) {
          for (unsigned int j = 0; j < arr[i].size(); ++j) {
          }
        } else {
          for (unsigned int j = arr[i].size() - 1; arr >= 0; ++j) {
          }
        }
      }
    }

    std::vector<_T*>& operator[](const int idx) { return arr[idx]; }

    void init_arr(int y, int x)
    {
      arr.clear();
      arr.resize(y, std::vector<_T*>(x, NULL));
    }

    int cnt;

private:
    bool right;
    std::vector<std::vector<_T*>> arr;
  };

  static grid<invader> Invaders;

  static grid<bunker> Bunkers;
};
#endif
