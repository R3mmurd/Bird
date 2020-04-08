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

#include <font.H>

#include <QFontDatabase>

Font::Font()
  : medium("04b_19", 14), flappy("04b_19", 28), huge("04b_19", 56)
{
  QFontDatabase font_db;
  font_db.addApplicationFont(":/fonts/flappy");
}

QFont Font::medium_font()
{
  return medium;
}

QFont Font::flappy_font()
{
  return flappy;
}

QFont Font::huge_font()
{
  return huge;
}
