#include "Board.hpp"
#include "Player.hpp"

#include <bitset>
#include <string_view>

// add board state stuff
// gets and sets board state

// assuming bottom left is a1 for now, and player 1 (bottom player) is white
// when swapping player, all pieces start at same spot, but bottom left is now h8
// board should print from perspective of human player at all times.

namespace chess
{

Board::Board()
    : board_{0xFFFF00000000FFFF}, piece_boards_({
                                      {0x0000FFFFFFFF0000}, // empty
                                      {0x00FF00000000FF00}, // pawn
                                      {0x2400000000000024}, // bishop
                                      {0x4200000000000042}, // knight
                                      {0x8100000000000081}, // rook
                                      {0x1000000000000010}, // queen
                                      {0x0800000000000008}  // king
                                  }),
      orientation_{BoardOrientation::a_left}
{
}

Board::Board(BoardOrientation orientation)
    : board_{0xFFFF00000000FFFF}, piece_boards_({
                                      {0x0000FFFFFFFF0000}, // empty
                                      {0x00FF00000000FF00}, // pawn
                                      {0x2400000000000024}, // bishop
                                      {0x4200000000000042}, // knight
                                      {0x8100000000000081}, // rook
                                      {0x1000000000000010}, // queen
                                      {0x0800000000000008}  // king
                                  }),
      orientation_{orientation}
{
}

Board::Board(const chess::Player& player1)
    : board_{0xFFFF00000000FFFF}, piece_boards_({
                                      {0x0000FFFFFFFF0000}, // empty
                                      {0x00FF00000000FF00}, // pawn
                                      {0x2400000000000024}, // bishop
                                      {0x4200000000000042}, // knight
                                      {0x8100000000000081}, // rook
                                      {0x1000000000000010}, // queen
                                      {0x0800000000000008}  // king
                                  })
{
   setBoardOrientation(player1);
}

// always print board from player1's perspective

void Board::setBoardOrientation(const Player& player)
{
   const static PlayerNumber player_number{player.getPlayerNumber()};
   const static Color player_color{player.getPlayerColor()};

   if ((player_number == PlayerNumber::Player_1 && player_color == Color::white) ||
       player_number == PlayerNumber::Player_2 && player_color == Color::black)
      orientation_ = BoardOrientation::a_left;
   else
      orientation_ = BoardOrientation::h_right;
}

bitboard Board::getBoard() const
{
   return board_;
}

bitboard Board::getPieceBoard(PieceType piece) const
{
   return piece_boards_[std::to_underlying(piece)];
}

// ----------------------------- Non member functions ------------------------------

std::string_view PieceTypeToChar(const chess::PieceType piece_type, const chess::Color player_color)
{
   switch (player_color)
   {
   case chess::Color::white:
      switch (piece_type)
      {
      case chess::PieceType::pawn:
         return "P";
      case chess::PieceType::bishop:
         return "B";
      case chess::PieceType::knight:
         return "N";
      case chess::PieceType::rook:
         return "R";
      case chess::PieceType::queen:
         return "Q";
      case chess::PieceType::king:
         return "K";
      default:
         return "-";
         break;
      }
   case chess::Color::black:
      switch (piece_type)
      {
      case chess::PieceType::pawn:
         return "p";
      case chess::PieceType::bishop:
         return "b";
      case chess::PieceType::knight:
         return "n";
      case chess::PieceType::rook:
         return "r";
      case chess::PieceType::queen:
         return "q";
      case chess::PieceType::king:
         return "k";
      default:
         return "-";
         break;
      }
   default:
      return "-";
      break;
   }
}

chess::PieceType getPieceTypeAtSquare(const bitboard piece_index, const chess::Board& game_board)
{
   if (std::bitset<1>((game_board.getBoard() & game_board.getPieceBoard(chess::PieceType::pawn)) >> piece_index) == 1)
   {
      return chess::PieceType::pawn;
   }
   else if (std::bitset<1>((game_board.getBoard() & game_board.getPieceBoard(chess::PieceType::bishop)) >>
                           piece_index) == 1)
   {
      return chess::PieceType::bishop;
   }
   else if (std::bitset<1>((game_board.getBoard() & game_board.getPieceBoard(chess::PieceType::knight)) >>
                           piece_index) == 1)
   {
      return chess::PieceType::knight;
   }
   else if (std::bitset<1>((game_board.getBoard() & game_board.getPieceBoard(chess::PieceType::rook)) >> piece_index) ==
            1)
   {
      return chess::PieceType::rook;
   }
   else if (std::bitset<1>((game_board.getBoard() & game_board.getPieceBoard(chess::PieceType::queen)) >>
                           piece_index) == 1)
   {
      return chess::PieceType::queen;
   }
   else if (std::bitset<1>((game_board.getBoard() & game_board.getPieceBoard(chess::PieceType::king)) >> piece_index) ==
            1)
   {
      return chess::PieceType::king;
   }
   else
      return chess::PieceType::none;
}

void printSpecificBoard(bitboard b)
{
   std::cout << '\n';
   for (size_t bit = (sizeof(bitboard) * 8); bit > 0; bit--)
   {
      std::cout << std::bitset<1>{b >> (bit - 1)} << " ";
      if ((bit - 1) % 8 == 0)
         std::cout << '\n';
   }
   std::cout << '\n';
}

void printGameBoard(const Board& board)
{
   if (board.getBoardOrientation() == BoardOrientation::a_left)
   {
      for (size_t bit = (sizeof(bitboard) * 8); bit > 0; bit--)
      {
         if ((bit) % 8 == 0)
            std::cout << '\n' << ((bit - 1) / 8) + 1 << "   ";
         std::cout << PieceTypeToChar(getPieceTypeAtSquare(bit - 1, board), player.getPlayerColor()) << " ";
      }
      std::cout << "\n\n" << "    a b c d e f g h";
   }
   else
   {
      for (size_t rank = 8; rank > 0; rank--)
      {
         std::cout << '\n' << 8 - rank + 1 << "   ";
         for (size_t file = 1; file <= 8; file++)
         {
            std::cout << PieceTypeToChar(getPieceTypeAtSquare((rank * 8) - file, board), player.getPlayerColor())
                      << " ";
         }
      }
      std::cout << "\n\n" << "    h g f e d c b a";
   }
   std::cout << "\n\n";
}

} // namespace chess