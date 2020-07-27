/*
  Fatty Bird (a Flappy Bird remake).
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

#include <global.H>

const unsigned Global::RANDOM_SEED =
    std::chrono::system_clock::now().time_since_epoch().count();

bool Global::pause = false;

GameMode * Global::game_mode = GameModeNormal::get_ptr_instance();
