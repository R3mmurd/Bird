/*
  Bird (a Flappy Bird remake).
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <random>

#include <singleton.H>

class GameMode
{
public:
  GameMode();

  virtual double get_pipes_time() const = 0;

  virtual double get_pipes_gap() const = 0;

  virtual int get_num_stars(int) const = 0;
};


class GameModeNormal :
    public GameMode,
    public Singleton<GameModeNormal>
{
  static constexpr double PIPES_SPAWN_TIME = 1.5;
  static constexpr double PIPES_GAP = 90;

public:
  double get_pipes_time() const override;

  double get_pipes_gap() const override;

  int get_num_stars(int) const override;
};

class GameModeChallenging :
    public GameMode,
    public Singleton<GameModeChallenging>
{
  static constexpr double MIN_PIPES_SPAWN_TIME = 0.8;
  static constexpr double MAX_PIPES_SPAWN_TIME = 2.0;
  static constexpr double MIN_PIPES_GAP = 70;
  static constexpr double MAX_PIPES_GAP = 100;

  mutable std::mt19937_64 rng;
  mutable std::uniform_real_distribution<double> spawn_time_dist;
  mutable std::uniform_real_distribution<double> gap_dist;

public:
  GameModeChallenging();

  double get_pipes_time() const override;

  double get_pipes_gap() const override;

  int get_num_stars(int) const override;
};

#endif // GAMEMODE_H
