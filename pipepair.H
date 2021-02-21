/*
  Bird (a Flappy Bird remake).
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

#ifndef PIPEPAIR_H
#define PIPEPAIR_H

#include <bird.H>
#include<pipe.H>

class PipePair
{
  double x;
  double y;
  Pipe top;
  Pipe bottom;
  bool scored;

public:
  PipePair(double y);

  void update(double);

  void draw(QPainter &) const;

  bool is_out_of_game() const;

  bool collide(const Bird &) const;

  bool update_scored(const Bird &);
};

#endif // PIPEPAIR_H
