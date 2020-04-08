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

#ifndef GAMEMAIN_H
#define GAMEMAIN_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QPixmap>
#include <QList>

#include <statemachine.H>
#include <world.H>
#include <bird.H>

class GameMain :
    public QWidget,
    public StateMachine<GameMain>
{
  Q_OBJECT

  QTime time;
  QTimer timer;

  World world;
  Bird bird;
  int score;

public:
  explicit GameMain(QWidget *parent = nullptr);

  void paintEvent(QPaintEvent *event) override;

  void keyPressEvent(QKeyEvent *event) override;

  World & get_world();

  const World & get_world() const;

  Bird & get_bird();

  const Bird & get_bird() const;

  int get_score() const;

  void set_score(int);

  void inc_score();

  void reset();

public slots:
  void update_loop();
};

#endif // GAMEMAIN_H
