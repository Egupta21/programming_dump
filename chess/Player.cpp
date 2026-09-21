#include "Player.hpp"

namespace chess
{
Player::Player() : player_color_{Color::white}, player_num_{PlayerNumber::Player_1}
{
   setPlayerBoard();
}

Player::Player(const Color player_color, const PlayerNumber player_number)
    : player_color_{player_color}, player_num_{player_number}
{
   setPlayerBoard();
}

void Player::setPlayerBoard()
{
   if (player_num_ == PlayerNumber::Player_1 && player_color_ == Color::white ||
       player_num_ == PlayerNumber::Player_2 && player_color_ == Color::black)
   {
      player_board_ = {0x000000000000FFFF};
   }
   else
   {
      player_board_ = {0xFFFF000000000000};
   }
}

bitboard Player::getPlayerBoard() const
{
   return player_board_;
}

Color Player::getPlayerColor() const
{
   return player_color_;
}

PlayerNumber Player::getPlayerNumber() const
{
   return player_num_;
}
} // namespace chess