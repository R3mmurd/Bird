/*
  Fatty Bird (a Flappy Bird remake).
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

#ifndef GAMECANVAS_H
#define GAMECANVAS_H

#include <random>

#include <QPixmap>

#include <bird.H>
#include <pipepair.H>

class World
{
  static constexpr int BACKGROUND_LOOPING_POINT = 413;

  std::mt19937_64 rng;

  double background_x;
  double ground_x;

  QPixmap background;
  QPixmap ground;

  QList<PipePair> pipes;

  double pipes_spawn_timer;
  double current_pipes_spawn_time;

  int last_pipe_y;

  bool generate_pipes;


public:
  World();

  void draw(QPainter &);

  void update(double);

  bool collide(const Bird &) const;

  void reset();

  void start();

  bool update_scored(const Bird &);
};

#endif // GAMECANVAS_H
