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

#include <gamemode.H>

GameMode::GameMode()
{
  // Empty
}

double GameModeNormal::get_pipes_time() const
{
  return PIPES_SPAWN_TIME;
}

double GameModeNormal::get_pipes_gap() const
{
  return PIPES_GAP;
}

int GameModeNormal::get_num_stars(int score) const
{
  if (score > 20)
    return 3;
  else if (score >= 12)
    return 2;
  else if (score >= 5)
    return 1;
  return 0;
}

GameModeChallenging::GameModeChallenging()
  : rng(time(0) % std::mt19937_64::max()),
    spawn_time_dist(MIN_PIPES_SPAWN_TIME, MAX_PIPES_SPAWN_TIME),
    gap_dist(MIN_PIPES_GAP, MAX_PIPES_GAP)
{
  // Empty
}

double GameModeChallenging::get_pipes_time() const
{
  return spawn_time_dist(rng);
}

double GameModeChallenging::get_pipes_gap() const
{
  return gap_dist(rng);
}

int GameModeChallenging::get_num_stars(int score) const
{
  if (score > 15)
    return 3;
  else if (score >= 10)
    return 2;
  else if (score >= 5)
    return 1;
  return 0;
}
