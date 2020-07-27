/*
  Fatty Bird (a Flappy Bird remake).
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

#ifndef GLOBAL_H
#define GLOBAL_H

#include <chrono>
#include <gamemode.H>

class Global
{
public:
  static constexpr int WINDOW_WIDTH = 1280;
  static constexpr int WINDOW_HEIGHT = 720;
  static constexpr int VIRTUAL_WIDTH = 512;
  static constexpr int VIRTUAL_HEIGHT = 288;
  static constexpr double H_SCALE = double(WINDOW_WIDTH)/double(VIRTUAL_WIDTH);
  static constexpr double V_SCALE =
      double(WINDOW_HEIGHT)/double(VIRTUAL_HEIGHT);
  static constexpr double GRAVITY = 20;
  static constexpr double MAIN_SCROLL_SPEED = -100;
  static constexpr double BACK_SCROLL_SPEED = -50;
  static constexpr int PIPE_HEIGHT = 288;
  static constexpr int PIPE_WIDTH = 70;
  static const unsigned RANDOM_SEED;
  static bool pause;
  static GameMode * game_mode;
};

#endif // GLOBAL_H
