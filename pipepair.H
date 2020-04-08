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

#ifndef PIPEPAIR_H
#define PIPEPAIR_H

#include <bird.H>
#include<pipe.H>

class PipePair
{
  double x;
  double y;
  Pipe top;
  Pipe bottom;
  bool scored;

public:
  PipePair(double y);

  void update(double);

  void draw(QPainter &) const;

  bool is_out_of_game() const;

  bool collide(const Bird &) const;

  bool update_scored(const Bird &);
};

#endif // PIPEPAIR_H
