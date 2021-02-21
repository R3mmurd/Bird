/*
  Bird (a Flappy Bird remake).
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

#include <pipe.H>

#include <QPainter>

#include <global.H>

Pipe::Pipe(double _x, double _y)
  : image(":/images/pipe"), x(_x), y(_y)
{

}

void Pipe::update(double _x)
{
  x = _x;
}

void Pipe::draw(QPainter & painter) const
{
  painter.drawPixmap(x, y, image);
}

QRectF Pipe::get_collision_rect() const
{
  return QRectF(x, y, Global::PIPE_WIDTH, Global::PIPE_HEIGHT);
}
