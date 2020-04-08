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

#include <world.H>
#include <QPainter>

#include <global.H>

#include <cmath>

World::World()
  :
    rng(Global::RANDOM_SEED),
    background_x(0), ground_x(0),
    background(":/images/background"),
    ground(":/images/ground"),
    pipes_spawn_timer(0),
    current_pipes_spawn_time(Global::game_mode->get_pipes_time()),
    last_pipe_y(0), generate_pipes(false)
{
  std::uniform_int_distribution<int> dist(0, 80);
  last_pipe_y = -Global::PIPE_HEIGHT + dist(rng) + 20;
}

void World::draw(QPainter & painter)
{
  painter.drawPixmap(background_x, 0, background);
  for (const PipePair & pipe_pair : pipes)
    pipe_pair.draw(painter);
  painter.drawPixmap(ground_x, Global::VIRTUAL_HEIGHT-16, ground);
}

void World::update(double dt)
{
  if(generate_pipes)
    {
      pipes_spawn_timer += dt;

      if (pipes_spawn_timer > current_pipes_spawn_time)
        {
          std::uniform_int_distribution<int> dist(-20, 20);
          pipes_spawn_timer = 0;
          int y = std::max(-Global::PIPE_HEIGHT + 10,
                           std::min(last_pipe_y + dist(rng),
                                    Global::VIRTUAL_HEIGHT + 90
                                    - Global::PIPE_HEIGHT));
          last_pipe_y = y;
          pipes.append(PipePair(y));
          current_pipes_spawn_time = Global::game_mode->get_pipes_time();
        }
    }

  background_x = background_x + Global::BACK_SCROLL_SPEED*dt;
  if (background_x <= -BACKGROUND_LOOPING_POINT)
    background_x = 0;

  ground_x = ground_x + Global::MAIN_SCROLL_SPEED*dt;
  if (ground_x <= -Global::VIRTUAL_WIDTH)
    ground_x = 0;

  QMutableListIterator<PipePair> it(pipes);

  while (it.hasNext())
    {
        PipePair & pipe_pair = it.next();
      if (pipe_pair.is_out_of_game())
        it.remove();
      else
        pipe_pair.update(dt);
    }
}

bool World::collide(const Bird & bird) const
{
  QRectF collision_rect = bird.get_collision_rect();

  if (collision_rect.bottom() > Global::VIRTUAL_HEIGHT-10
      or collision_rect.bottom() < 0)
    return true;

  for (const PipePair & pipe_pair : pipes)
    if (pipe_pair.collide(bird))
      return true;

  return false;
}

void World::reset()
{
  pipes.clear();
  pipes_spawn_timer = 0;
  generate_pipes = false;
}

void World::start()
{
  generate_pipes= true;
}

bool World::update_scored(const Bird & bird)
{
  for (PipePair & pipe_pair : pipes)
    if (pipe_pair.update_scored(bird))
      return true;

  return false;
}
