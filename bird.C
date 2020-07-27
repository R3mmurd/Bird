/*
  Fatty Bird (a Flappy Bird remake).
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

#include <bird.H>

#include <QPainter>

#include <global.H>
#include <audio.H>


Bird::Bird(double _x, double _y)
  : image(":/images/bird"),
    width(image.width()), height(image.height()),
    x(_x - width/2), y(_y - height/2), dy(0), jumping(false)
{
  // Empty
}

void Bird::update(double dt)
{
  dy += Global::GRAVITY*dt;
  if (jumping)
    {
      Audio::get_instance().play_jump();
      dy = -5;
      jumping = false;
    }
  y += dy;
}

void Bird::draw(QPainter & painter) const
{
  painter.drawPixmap(x, y, image);
}

void Bird::jump()
{
  jumping = true;
}

QRectF Bird::get_collision_rect() const
{
  return QRect(x + 2, y + 2, width - 4, height - 4);
}

void Bird::reset(double _x, double _y)
{
  x = _x - width/2;
  y = _y - height/2;
  dy = 0;
  jumping = false;
}
