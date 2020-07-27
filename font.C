/*
  Fatty Bird (a Flappy Bird remake).
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

#include <font.H>

#include <QFontDatabase>

Font::Font()
{
  QFontDatabase font_db;
  int id = font_db.addApplicationFont(":/fonts/flappy");
  QStringList families = font_db.applicationFontFamilies(id);
  medium.setFamily(families.first());
  medium.setPointSize(14);
  flappy.setFamily(families.first());
  flappy.setPointSize(28);
  huge.setFamily(families.first());
  huge.setPointSize(56);
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
