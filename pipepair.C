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

#include <pipepair.H>

#include <QPainter>

#include <global.H>

PipePair::PipePair(double _y)
  : x(Global::VIRTUAL_WIDTH), y(_y), top(x, y),
    bottom(x, y + Global::game_mode->get_pipes_gap() + Global::PIPE_HEIGHT),
    scored(false)
{
  // Empty
}

void PipePair::update(double dt)
{
  x += Global::MAIN_SCROLL_SPEED*dt;
  top.update(x);
  bottom.update(x);
}

void PipePair::draw(QPainter & painter) const
{
  double dx = 2*x + Global::PIPE_WIDTH;
  double dy = 2*y + Global::PIPE_HEIGHT;
  QMatrix matrix = painter.matrix();
  painter.translate(dx, dy);
  painter.rotate(180);
  top.draw(painter);
  painter.setMatrix(matrix);
  bottom.draw(painter);
}

bool PipePair::is_out_of_game() const
{
  return x < -Global::PIPE_WIDTH;
}

bool PipePair::collide(const Bird & bird) const
{
  QRectF bird_collision_rect = bird.get_collision_rect();

  return bird_collision_rect.intersects(top.get_collision_rect())
      or bird_collision_rect.intersects(bottom.get_collision_rect());
}

bool PipePair::update_scored(const Bird & bird)
{
  if (scored)
    return false;

  if (bird.get_collision_rect().x() > x + Global::PIPE_WIDTH)
    {
      scored = true;
      return true;
    }

  return false;
}

