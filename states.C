/*
  Fatty Bird (a Flappy Bird remake).
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

#include <states.H>
#include <gamemain.H>
#include <font.H>
#include <audio.H>

#include <QPixmap>

TitleScreenState::TitleScreenState()
  : feather(":/images/feather"), is_challenging_mode(false)
{
  selection[0] = {GameModeNormal::get_ptr_instance(), 110};
  selection[1] = {GameModeChallenging::get_ptr_instance(), 140};
}

void TitleScreenState::draw(GameMain *, QPainter & painter)
{
  painter.setFont(Font::get_instance().flappy_font());
  painter.drawText(0, 0, Global::VIRTUAL_WIDTH, Global::VIRTUAL_HEIGHT/2,
                   Qt::AlignCenter, QString("Fatty Bird"));
  painter.setFont(Font::get_instance().medium_font());
  painter.drawPixmap(Global::VIRTUAL_WIDTH/2.0+60,
                     selection[int(is_challenging_mode)].y, feather);
  painter.drawText(0, selection[0].y,
      Global::VIRTUAL_WIDTH, 28,
                   Qt::AlignCenter, QString("Normal"));
  painter.drawText(0, selection[1].y,
      Global::VIRTUAL_WIDTH, 28,
                   Qt::AlignCenter, QString("Challenging"));
  painter.drawText(0, 130, Global::VIRTUAL_WIDTH, Global::VIRTUAL_HEIGHT/2,
                   Qt::AlignCenter, QString("Press Enter"));
}

void TitleScreenState::key_pressed(GameMain * sm, QKeyEvent * event)
{
  if ((event->key() == Qt::Key_Down and is_challenging_mode)
      or (event->key() == Qt::Key_Up and not is_challenging_mode))
      return;

  if (event->key() == Qt::Key_Down or event->key() == Qt::Key_Up)
    {
      is_challenging_mode = not is_challenging_mode;
      Global::game_mode = selection[int(is_challenging_mode)].mode;
    }

  else if (event->key() == Qt::Key_Enter or event->key() == Qt::Key_Return)
    sm->change_state(CountDownState::get_ptr_instance());
}


void CountDownState::enter(GameMain *)
{
  count = 3;
  timer = 0;
}

void CountDownState::exec(GameMain * sm, double dt)
{
  timer += dt;

  if (timer >= COUNTDOWN_TIME)
    {
      --count;
      timer = timer - COUNTDOWN_TIME;
    }

  if (count == 0)
    sm->change_state(PlayState::get_ptr_instance());
}

void CountDownState::draw(GameMain *, QPainter & painter)
{
  painter.setFont(Font::get_instance().huge_font());
  painter.drawText(0, 0, Global::VIRTUAL_WIDTH, Global::VIRTUAL_HEIGHT,
                   Qt::AlignCenter, QString().setNum(count));

}

void PlayState::enter(GameMain * sm)
{
  sm->reset();
  sm->get_world().start();
}

void PlayState::exec(GameMain * sm, double dt)
{
  sm->get_bird().update(dt);

  if (sm->get_world().collide(sm->get_bird()))
    {
      Audio::get_instance().play_explosion();
      Audio::get_instance().play_hurt();
      sm->change_state(ScoreState::get_ptr_instance());
    }
  if (sm->get_world().update_scored(sm->get_bird()))
    {
      sm->inc_score();
      Audio::get_instance().play_score();
    }
}

void PlayState::exit(GameMain * sm)
{
  sm->get_world().reset();
}

void PlayState::draw(GameMain * sm, QPainter & painter)
{
  sm->get_bird().draw(painter);
  painter.setFont(Font::get_instance().flappy_font());
  painter.drawText(8, 4, Global::VIRTUAL_WIDTH, Global::VIRTUAL_HEIGHT/6,
                   Qt::AlignLeft,
                   QString("Score: ") + QString().setNum(sm->get_score()));
}

void PlayState::key_pressed(GameMain * sm, QKeyEvent *event)

{
  if (event->key() == Qt::Key_P)
    {
      Global::pause = not Global::pause;
      Audio::get_instance().play_pause();
    }
  if (event->key() == Qt::Key_Space)
    sm->get_bird().jump();
}

ScoreState::ScoreState()
  : empty_star(":/images/empty-star"), fill_star(":/images/fill-star")
{
  // Empty
}

void ScoreState::draw(GameMain * sm, QPainter & painter)
{
  int num_stars = Global::game_mode->get_num_stars(sm->get_score());

  double star_x = Global::VIRTUAL_WIDTH/2.0 - 3.0*empty_star.width()/2.0 - 2;
  double star_y = 30;

  int i = 0;

  while (i < num_stars)
    {
      ++i;
      painter.drawPixmap(star_x, star_y, fill_star);
      star_x += fill_star.width() + 2;
    }

  while (i < 3)
    {
      ++i;
      painter.drawPixmap(star_x, star_y, empty_star);
      star_x += fill_star.width() + 2;
    }

  painter.setFont(Font::get_instance().flappy_font());
  painter.drawText(0, 0, Global::VIRTUAL_WIDTH, 3*Global::VIRTUAL_HEIGHT/4,
                   Qt::AlignCenter, QString("Ohhh! You lost!"));
  painter.setFont(Font::get_instance().medium_font());
  painter.drawText(0, 30, Global::VIRTUAL_WIDTH, 3*Global::VIRTUAL_HEIGHT/4,
                   Qt::AlignCenter,
                   QString("Score: ") + QString().setNum(sm->get_score()));
  painter.drawText(0, 70, Global::VIRTUAL_WIDTH, 3*Global::VIRTUAL_HEIGHT/4,
                   Qt::AlignCenter, QString("Press Enter to play again!"));
}

void ScoreState::key_pressed(GameMain * sm, QKeyEvent * event)
{
  if (event->key() == Qt::Key_Enter or event->key() == Qt::Key_Return)
    sm->change_state(TitleScreenState::get_ptr_instance());
}
