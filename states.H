/*
  Fatty Bird (a Flappy Bird remake).
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

#ifndef STATES_H
#define STATES_H

#include <statemachine.H>
#include <singleton.H>

#include <world.H>
#include <bird.H>
#include <global.H>

class GameMain;

class TitleScreenState :
    public State<GameMain>,
    public Singleton<TitleScreenState>
{  
  QPixmap feather;

  struct Item
  {
    GameMode * mode;
    int y;
  };

  Item selection[2];

  bool is_challenging_mode;

public:
  TitleScreenState();

  void draw(GameMain *, QPainter &) override;

  void key_pressed(GameMain *, QKeyEvent *) override;
};

class CountDownState :
    public State<GameMain>,
    public Singleton<CountDownState>
{
  static constexpr double COUNTDOWN_TIME = 0.75;
  int count;
  double timer;

public:
  void enter(GameMain *) override;

  void exec(GameMain *, double) override;

  void draw(GameMain *, QPainter &) override;
};

class PlayState :
    public State<GameMain>,
    public Singleton<PlayState>
{
public:
  void enter(GameMain *) override;

  void exec(GameMain *, double) override;

  void exit(GameMain *) override;

  void draw(GameMain *, QPainter &) override;

  void key_pressed(GameMain *, QKeyEvent *) override;
};

class ScoreState :
    public State<GameMain>,
    public Singleton<ScoreState>
{
  QPixmap empty_star;
  QPixmap fill_star;

public:
  ScoreState();

  void draw(GameMain *, QPainter &) override;

  void key_pressed(GameMain *, QKeyEvent *) override;
};



#endif // STATES_H
