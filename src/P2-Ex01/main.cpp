#include "pch.h"
#include "board.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"

int main() {
    Board chessBoard;

    // Place some initial pieces
    ChessPiece* whiteKing = new King('W', "E1");
    ChessPiece* blackKing = new King('B', "E8");
    ChessPiece* whitePawn = new Pawn('W', "D1");

    chessBoard.placePiece(whiteKing, "E1");
    chessBoard.placePiece(blackKing, "E8");
    chessBoard.placePiece(whitePawn, "D1");

    // Display the initial board
    chessBoard.display();

    std::string fromPos, toPos;
    bool gameRunning = true;

    while (gameRunning) {
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
    }

    return 0;
}