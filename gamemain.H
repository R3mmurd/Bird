  /*
  Bird (a Flappy Bird remake).
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

#ifndef GAMEMAIN_H
#define GAMEMAIN_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QPixmap>
#include <QList>

#include <statemachine.H>
#include <world.H>
#include <bird.H>

class GameMain :
    public QWidget,
    public StateMachine<GameMain>
{
  Q_OBJECT

  QTime time;
  QTimer timer;

  World world;
  Bird bird;
  int score;

public:
  explicit GameMain(QWidget *parent = nullptr);

  void paintEvent(QPaintEvent *event) override;

  void keyPressEvent(QKeyEvent *event) override;

  World & get_world();

  const World & get_world() const;

  Bird & get_bird();

  const Bird & get_bird() const;

  int get_score() const;

  void set_score(int);

  void inc_score();

  void reset();

public slots:
  void update_loop();
};

#endif // GAMEMAIN_H
