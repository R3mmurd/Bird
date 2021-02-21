/*
  Bird (a Flappy Bird remake).
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

#ifndef FONT_H
#define FONT_H

#include <QFont>

#include <singleton.H>

class Font : public Singleton<Font>
{
  QFont medium;
  QFont flappy;
  QFont huge;

public:
  Font();

  QFont medium_font();

  QFont flappy_font();

  QFont huge_font();
};

#endif // FONT_H
