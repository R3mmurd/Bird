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

#include <audio.H>

Audio::Audio()
{
  explosion = new QSound(":audio/explosion");
  hurt = new QSound(":audio/hurt");
  jump = new QSound(":audio/jump");
  music = new QSound(":audio/music");
  score = new QSound(":audio/score");
  pause = new QSound(":/audio/pause");
}

void Audio::play_explosion()
{
  explosion->play();
}

void Audio::play_hurt()
{
  hurt->play();
}

void Audio::play_jump()
{
  jump->play();
}

void Audio::play_score()
{
  score->play();
}

void Audio::play_music()
{
  music->setLoops(QSound::Infinite);
  music->play();
}

void Audio::stop_music()
{
  music->stop();
}

void Audio::play_pause()
{
  pause->play();
}
