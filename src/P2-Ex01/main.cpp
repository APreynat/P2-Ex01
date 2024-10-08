#include "pch.h"
#include "Board.h"
#include "Player.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"
#include "rook.h"
#include "Bishop.h"
#include "knight.h"

int main() {
    Board chessBoard;

    // Create two players
    Player player1("Player 1", 'W');
    Player player2("Player 2", 'B');

    // Place initial pieces for Player 1 (white)
    ChessPiece* whiteKing = new King('W', "E1");
    ChessPiece* whiteQueen = new Queen('W', "D1");
    ChessPiece* whiteRook1 = new Rook('W', "A1");
    ChessPiece* whiteRook2 = new Rook('W', "H1");
    ChessPiece* whiteBishop1 = new Bishop('W', "C1");
    ChessPiece* whiteBishop2 = new Bishop('W', "F1");
    ChessPiece* whiteKnight1 = new Knight('W', "B1");
    ChessPiece* whiteKnight2 = new Knight('W', "G1");

    // Place pawns for Player 1
    for (int i = 0; i < 8; i++) {
        char col = 'A' + i;
        string pos = string(1, col) + "2";
        ChessPiece* pawn = new Pawn('W', pos);
        chessBoard.placePiece(pawn, pos);
    }

    // Place pieces for Player 1 on the board
    chessBoard.placePiece(whiteKing, "E1");
    chessBoard.placePiece(whiteQueen, "D1");
    chessBoard.placePiece(whiteRook1, "A1");
    chessBoard.placePiece(whiteRook2, "H1");
    chessBoard.placePiece(whiteBishop1, "C1");
    chessBoard.placePiece(whiteBishop2, "F1");
    chessBoard.placePiece(whiteKnight1, "B1");
    chessBoard.placePiece(whiteKnight2, "G1");

    // Place initial pieces for Player 2 (black)
    ChessPiece* blackKing = new King('B', "E8");
    ChessPiece* blackQueen = new Queen('B', "D8");
    ChessPiece* blackRook1 = new Rook('B', "A8");
    ChessPiece* blackRook2 = new Rook('B', "H8");
    ChessPiece* blackBishop1 = new Bishop('B', "C8");
    ChessPiece* blackBishop2 = new Bishop('B', "F8");
    ChessPiece* blackKnight1 = new Knight('B', "B8");
    ChessPiece* blackKnight2 = new Knight('B', "G8");

    // Place pawns for Player 2
    for (int i = 0; i < 8; i++) {
        char col = 'A' + i;
        string pos = string(1, col) + "7";
        ChessPiece* pawn = new Pawn('B', pos);
        chessBoard.placePiece(pawn, pos);
    }

    // Place pieces for Player 2 on the board
    chessBoard.placePiece(blackKing, "E8");
    chessBoard.placePiece(blackQueen, "D8");
    chessBoard.placePiece(blackRook1, "A8");
    chessBoard.placePiece(blackRook2, "H8");
    chessBoard.placePiece(blackBishop1, "C8");
    chessBoard.placePiece(blackBishop2, "F8");
    chessBoard.placePiece(blackKnight1, "B8");
    chessBoard.placePiece(blackKnight2, "G8");

    // Set initial turn to Player 1 (White)
    player1.setTurn(true);

    // Display the initial board
    chessBoard.display();

    bool gameRunning = true;

    while (gameRunning) {
        if (player1.getTurn()) {
            cout << "Player 1's move (White)" << endl;
            player1.makeMove(chessBoard);
            player1.setTurn(false);
            player2.setTurn(true);
        }
        else {
            cout << "Player 2's move (Black)" << endl;
            player2.makeMove(chessBoard);
            player2.setTurn(false);
            player1.setTurn(true);
        }

        // Display the updated board after each move
        chessBoard.display();

        // Game exit condition: You can add a condition to stop the game if needed
        // For now, it loops until the program is terminated
    }

    return 0;
}
