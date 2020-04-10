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

#ifndef STATES_H
#define STATES_H

#include <statemachine.H>
#include <singleton.H>

#include <world.H>
#include <bird.H>
#include <global.H>

class GameMain;

class TitleScreenState :
    public State<GameMain>,
    public Singleton<TitleScreenState>
{  
  QPixmap feather;

  struct Item
  {
    GameMode * mode;
    int y;
  };

  Item selection[2];

  bool is_challenging_mode;

public:
  TitleScreenState();

  void draw(GameMain *, QPainter &) override;

  void key_pressed(GameMain *, QKeyEvent *) override;
};

class CountDownState :
    public State<GameMain>,
    public Singleton<CountDownState>
{
  static constexpr double COUNTDOWN_TIME = 0.75;
  int count;
  double timer;

public:
  void enter(GameMain *) override;

  void exec(GameMain *, double) override;

  void draw(GameMain *, QPainter &) override;
};

class PlayState :
    public State<GameMain>,
    public Singleton<PlayState>
{
public:
  void enter(GameMain *) override;

  void exec(GameMain *, double) override;

  void exit(GameMain *) override;

  void draw(GameMain *, QPainter &) override;

  void key_pressed(GameMain *, QKeyEvent *) override;
};

class ScoreState :
    public State<GameMain>,
    public Singleton<ScoreState>
{
  QPixmap empty_star;
  QPixmap fill_star;

public:
  ScoreState();

  void draw(GameMain *, QPainter &) override;

  void key_pressed(GameMain *, QKeyEvent *) override;
};



#endif // STATES_H
