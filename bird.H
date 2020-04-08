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

#ifndef BIRD_H
#define BIRD_H

#include <QPixmap>

class Bird
{
  QPixmap image;
  double width;
  double height;
  double x;
  double y;
  double dy;
  bool jumping;

public:
  Bird(double, double);

  void update(double);

  void draw(QPainter &) const;

  void jump();

  QRectF get_collision_rect() const;

  void reset(double, double);
};

#endif // BIRD_H
