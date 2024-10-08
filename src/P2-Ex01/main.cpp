#include "pch.h"
#include "board.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"
#include "rook.h"
#include "Bishop.h"
#include "knight.h"

int main() {
    Board chessBoard;

    // Place some initial pieces
    ChessPiece* whiteKing = new King('W', "D1");
    ChessPiece* blackKing = new King('B', "E8");
    ChessPiece* whitePawn = new Pawn('W', "E2");
    ChessPiece* whiteQueen = new Queen('W', "E1");
    ChessPiece* whiteRook = new Rook('W', "A1");
    ChessPiece* whiteBishop = new Bishop('W', "C1");
    ChessPiece* whiteKnight = new Knight('W', "B1");

    chessBoard.placePiece(whiteKing, "D1");
    chessBoard.placePiece(blackKing, "E8");
    chessBoard.placePiece(whitePawn, "E2");
    chessBoard.placePiece(whiteQueen, "E1");
    chessBoard.placePiece(whiteBishop, "C1");
    chessBoard.placePiece(whiteKnight, "B1");
    chessBoard.placePiece(whiteRook, "A1");

    // Display the initial board
    chessBoard.display();

    std::string fromPos, toPos;
    bool gameRunning = true;

    // Move counter for demo mode
    int moveCount = 0;

    while (gameRunning) {
        // Check if the game should terminate after 3 moves in demo mode
#ifdef DEMO
        if (moveCount >= 3) {
            std::cout << "Demo version: Maximum 3 moves reached. Exiting the game." << std::endl;
            break;
        }
#endif

        // Get player input for movement
        std::cout << "Enter piece position to move (e.g., 'E2') or 'quit' to exit: ";
        std::cin >> fromPos;

        if (fromPos == "quit") {
            gameRunning = false;
            break;
        }

        // Ask where to move the piece
        std::cout << "Enter position to move to (e.g., 'E4'): ";
        std::cin >> toPos;

        // Attempt to move the piece (all checks are handled inside movePiece)
        if (!chessBoard.movePiece(fromPos, toPos)) {
            std::cout << "" << std::endl;
        }

        // Display the updated board
        chessBoard.display();

        // Increment move cou
    }

    return 0;
}
