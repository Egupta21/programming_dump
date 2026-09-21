#ifndef BOARD_HPP
#define BOARD_HPP

#include "Globals.hpp"

// Data handled by board class:

// -- Board State (full state, player state, piece state)
// -- whose move it is
namespace chess
{

class Player;

enum class PieceType
{
   none,
   pawn,
   bishop,
   knight,
   rook,
   queen,
   king,
};

enum class BoardOrientation
{
   a_left,
   h_right
};

class Board
{
 private:
   bitboard board_;
   std::array<bitboard, 7> piece_boards_;
   BoardOrientation orientation_;

   void setBoardOrientation(const Player& player);

 public:
   Board();
   Board(BoardOrientation orientation);
   Board(const Player& player1);

   bitboard getBoard() const;
   bitboard getPieceBoard(PieceType piece) const;
   BoardOrientation getBoardOrientation() const;

   void
};

void printGameBoard(const Board& board);
void printSpecificBoard(bitboard b);
std::string_view PieceTypeToChar(const PieceType piece_type, const Color player_color);
PieceType getPieceTypeAtSquare(const bitboard piece_index, const Board& game_board);

} // namespace chess

#endif