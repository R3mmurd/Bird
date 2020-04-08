/*
  This file is part of Fatty Bird game.
  Copyright (C) 2020 by Alejandro J. Mujica

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

  Any user request of this software, write to

  Alejandro Mujica

  aledrums@gmail.com
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
