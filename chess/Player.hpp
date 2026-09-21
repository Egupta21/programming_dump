#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Globals.hpp"

namespace chess
{

class Board;

enum class Color
{
   white,
   black
};

enum class PlayerNumber
{
   Player_1,
   Player_2
};

class Player
{
 private:
   PlayerNumber player_num_;
   Color player_color_;
   bitboard player_board_;

   void setPlayerBoard();

 public:
   Player();
   Player(const Color player_color, const PlayerNumber player_number);
   Color getPlayerColor() const;
   PlayerNumber getPlayerNumber() const;
   bitboard getPlayerBoard() const;
};

} // namespace chess

#endif