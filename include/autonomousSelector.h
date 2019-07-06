#ifndef AUTOSELECT_H
#define AUTOSELECT_H

#include "main.h"

enum class Alliance {
  red,
  blue
};

enum class startPosition {
  left_pole,
  middle_shortpole,
  right_pole,
  right_wallpole,
  skills,
  disabled
};

class autonomousSelector {
public:
  Alliance alliance = Alliance::red;
  startPosition startPos = startPosition::disabled;
  bool platform = true;

  void update();
  void teleop();
  void runSelector();

  void btn0();
  void btn1();
  void btn2();
};

#endif
