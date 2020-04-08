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

#ifndef GAMECANVAS_H
#define GAMECANVAS_H

#include <random>

#include <QPixmap>

#include <bird.H>
#include <pipepair.H>

class World
{
  static constexpr int BACKGROUND_LOOPING_POINT = 413;

  std::mt19937_64 rng;

  double background_x;
  double ground_x;

  QPixmap background;
  QPixmap ground;

  QList<PipePair> pipes;

  double pipes_spawn_timer;
  double current_pipes_spawn_time;

  int last_pipe_y;

  bool generate_pipes;


public:
  World();

  void draw(QPainter &);

  void update(double);

  bool collide(const Bird &) const;

  void reset();

  void start();

  bool update_scored(const Bird &);
};

#endif // GAMECANVAS_H
