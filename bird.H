/*
  Bird (a Flappy Bird remake).
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

#ifndef BIRD_H
#define BIRD_H

#include <QPixmap>

class Bird
{
  QPixmap image;
  double width;
  double height;
  double x;
  double y;
  double dy;
  bool jumping;

public:
  Bird(double, double);

  void update(double);

  void draw(QPainter &) const;

  void jump();

  QRectF get_collision_rect() const;

  void reset(double, double);
};

#endif // BIRD_H
