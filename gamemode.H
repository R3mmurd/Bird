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

#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <random>

#include <singleton.H>

class GameMode
{
public:
  GameMode();

  virtual double get_pipes_time() const = 0;

  virtual double get_pipes_gap() const = 0;

  virtual int get_num_stars(int) const = 0;
};


class GameModeNormal :
    public GameMode,
    public Singleton<GameModeNormal>
{
  static constexpr double PIPES_SPAWN_TIME = 1.5;
  static constexpr double PIPES_GAP = 90;

public:
  double get_pipes_time() const override;

  double get_pipes_gap() const override;

  int get_num_stars(int) const override;
};

class GameModeChallenging :
    public GameMode,
    public Singleton<GameModeChallenging>
{
  static constexpr double MIN_PIPES_SPAWN_TIME = 0.8;
  static constexpr double MAX_PIPES_SPAWN_TIME = 2.0;
  static constexpr double MIN_PIPES_GAP = 70;
  static constexpr double MAX_PIPES_GAP = 100;

  mutable std::mt19937_64 rng;
  mutable std::uniform_real_distribution<double> spawn_time_dist;
  mutable std::uniform_real_distribution<double> gap_dist;

public:
  GameModeChallenging();

  double get_pipes_time() const override;

  double get_pipes_gap() const override;

  int get_num_stars(int) const override;
};

#endif // GAMEMODE_H
