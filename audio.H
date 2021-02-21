/*
  Bird (a Flappy Bird remake).
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

#ifndef AUDIO_H
#define AUDIO_H

#include <QSound>

#include <singleton.H>

class Audio : public Singleton<Audio>
{
  QSound * explosion;
  QSound * hurt;
  QSound * jump;
  QSound * music;
  QSound * score;
  QSound * pause;
public:
  Audio();

  void play_explosion();

  void play_hurt();

  void play_jump();

  void play_score();

  void play_music();

  void stop_music();

  void play_pause();
};

#endif // AUDIO_H
