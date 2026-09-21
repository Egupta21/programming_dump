#include "Board.hpp"
#include "Player.hpp"

int main()
{
   using namespace chess;

   Player p1 = Player(Color::white, PlayerNumber::Player_1);
   // Player p2 = Player(Color::black, PlayerNumber::Player_2);

   Board game_board = Board(BoardOrientation::h_right);
   // Board game_board = Board(player1.getBoardOrientation());
   printSpecificBoard(game_board.getPieceBoard(PieceType::pawn));
   printSpecificBoard(game_board.getPieceBoard(PieceType::bishop));
   printSpecificBoard(game_board.getPieceBoard(PieceType::knight));
   printSpecificBoard(game_board.getPieceBoard(PieceType::rook));
   printSpecificBoard(game_board.getPieceBoard(PieceType::queen));
   printSpecificBoard(game_board.getPieceBoard(PieceType::king));

   printGameBoard(game_board);
}