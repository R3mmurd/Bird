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

#include <bird.H>

#include <QPainter>

#include <global.H>
#include <audio.H>


Bird::Bird(double _x, double _y)
  : image(":/images/bird"),
    width(image.width()), height(image.height()),
    x(_x - width/2), y(_y - height/2), dy(0), jumping(false)
{
  // Empty
}

void Bird::update(double dt)
{
  dy += Global::GRAVITY*dt;
  if (jumping)
    {
      Audio::get_instance().play_jump();
      dy = -5;
      jumping = false;
    }
  y += dy;
}

void Bird::draw(QPainter & p) const
{
  p.drawPixmap(x, y, image);
}

void Bird::jump()
{
  jumping = true;
}

QRectF Bird::get_collision_rect() const
{
  return QRect(x + 2, y + 2, width - 4, height - 4);
}

void Bird::reset(double _x, double _y)
{
  x = _x - width/2;
  y = _y - height/2;
  dy = 0;
  jumping = false;
}
