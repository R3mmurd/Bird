/*
  Fatty Bird (a Flappy Bird remake).
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

#include <audio.H>

Audio::Audio()
{
  explosion = new QSound(":audio/explosion");
  hurt = new QSound(":audio/hurt");
  jump = new QSound(":audio/jump");
  music = new QSound(":audio/music");
  score = new QSound(":audio/score");
  pause = new QSound(":/audio/pause");
}

void Audio::play_explosion()
{
  explosion->play();
}

void Audio::play_hurt()
{
  hurt->play();
}

void Audio::play_jump()
{
  jump->play();
}

void Audio::play_score()
{
  score->play();
}

void Audio::play_music()
{
  music->setLoops(QSound::Infinite);
  music->play();
}

void Audio::stop_music()
{
  music->stop();
}

void Audio::play_pause()
{
  pause->play();
}
