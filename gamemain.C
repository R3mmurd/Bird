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

#include <gamemain.H>
#include <QPainter>
#include <QKeyEvent>
#include <QMutableListIterator>

#include <global.H>

#include <states.H>
#include <audio.H>

GameMain::GameMain(QWidget *parent):
  QWidget(parent), StateMachine<GameMain>(TitleScreenState::get_ptr_instance()),
  bird(Global::VIRTUAL_WIDTH/2, Global::VIRTUAL_HEIGHT/2), score(0)
{
  this->setFixedSize(Global::WINDOW_WIDTH, Global::WINDOW_HEIGHT);

  connect(&timer, SIGNAL(timeout()), this, SLOT(update_loop()));
  Audio::get_instance().play_music();
  timer.start(33);
  time.start();
}

void GameMain::update_loop()
{
  double dt = time.elapsed()/1000.0;

  if (not Global::pause)
    {
       world.update(dt);
       StateMachine::update(dt);
    }

  this->repaint();
  time.restart();
}

void GameMain::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.setPen(Qt::white);
  painter.setBrush(Qt::white);
  painter.scale(Global::H_SCALE, Global::V_SCALE);
  world.draw(painter);
  StateMachine::draw(painter);
}

void GameMain::keyPressEvent(QKeyEvent * event)
{
  if (event->isAutoRepeat())
    return;

  StateMachine::key_pressed(event);
}

World & GameMain::get_world()
{
  return world;
}

const World & GameMain::get_world() const
{
  return world;
}

Bird & GameMain::get_bird()
{
  return bird;
}

const Bird & GameMain::get_bird() const
{
  return bird;
}

int GameMain::get_score() const
{
  return score;
}

void GameMain::set_score(int s)
{
  score = s;
}

void GameMain::inc_score()
{
  ++score;
}

void GameMain::reset()
{
  world.reset();
  bird.reset(Global::VIRTUAL_WIDTH/2, Global::VIRTUAL_HEIGHT/2);
  score = 0;
}

