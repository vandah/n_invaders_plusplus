#ifndef OBJECT
#define OBJECT

#include "../globals.h"

class player;
class invader;
class bunker;
class falling;

/// generic static object
class object {
  public:
  /// default constructor with initialization of the most important variables
  object();

  /// virtual default destructor
  virtual ~object();

  /// show the object
  virtual void redraw() const;

  /// delete pointers pointing to the object
  virtual void destroy();

  /// reset to default state
  void reset();

  /// position on the screen
  std::pair<int, int> pos;

  /// current look which should be printed on screen
  std::string current_look() const;

  /// switch look
  void next_look();

  /// current score
  static int score;

  /// current level
  static int level;

  /// current number of lives
  static int lives;

  protected:
  /// object's color
  virtual int color() const = 0;

  /// get an array of available looks
  virtual std::vector<std::string> get_looks() const = 0;

  /// which look should be displayed
  int choice;

  /// length of the current look
  int length;

  /// screen size
  static std::pair<int, int> size;

  /// array with pointers to all objects on the screen -> for collision checks
  static std::vector<std::vector<object*>> battlefield;

  /// the player's ship
  static player* Player;

  /// smart array
  template <typename _T> class grid {
public:
    /// default constructor
    grid()
        : pos({ 0, 0 })
        , old_pos({ 0, 0 })
        , counter(0)
        , right(true)
    {
    }

    /// default destructor
    ~grid() { clear(); }

    /// position on the screen
    std::pair<int, int> pos;

    /// old position before movement
    std::pair<int, int> old_pos;

    /// counter for slowing time down
    int counter;

    /// returns whether the array is empty
    bool empty() { return arr.empty(); }

    /// returns size of the inner array
    unsigned int size() { return arr.size(); }

    /// clears the array
    void clear()
    {
      for (unsigned int i = 0; i < arr.size(); ++i) {
        arr[i].clear();
      }
      arr.clear();
    }

    /// emulates vector behavior
    std::vector<_T*>& operator[](const int idx) { return arr[idx]; }

    /// initialize new array of specified size and fill with NULLs
    void init_arr(int y, int x)
    {
      arr.clear();
      missiles.clear();
      arr.resize(y, std::vector<_T*>(x, NULL));
      missiles.resize(y, std::vector<falling*>(x, NULL));
    }

    /// missiles array - to allow missiles management
    std::vector<std::vector<falling*>> missiles;

    /// number of elements inside
    int cnt;

    /// whether the array is moving right
    bool right;

private:
    /// the actual array that is being wrapped arround
    std::vector<std::vector<_T*>> arr;
  };

  /// smart array of invaders
  static grid<invader> Invaders;

  /// smart array of bunkers
  static grid<bunker> Bunkers;
};
#endif
