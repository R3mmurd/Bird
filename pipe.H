/*
  Fatty Bird (a Flappy Bird remake).
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

#ifndef PIPE_H
#define PIPE_H

#include <QPixmap>

class Pipe
{
  QPixmap image;
  double x;
  double y;

public:
  Pipe(double, double);

  void update(double x);

  void draw(QPainter &) const;

  QRectF get_collision_rect() const;
};

#endif // PIPE_H
