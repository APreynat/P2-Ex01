#include "pch.h"
#include "Queen.h"

Queen::Queen(char color, string position) : ChessPiece(color, 'Q', position) {}

bool Queen::isValidMove(string newPosition, ChessPiece* grid[8][8]) const {

    // Extract current position row and column
    int currentRow = position[1] - '1';
    int currentCol = position[0] - 'A';  

    // Extract new position row and column
    int newRow = newPosition[1] - '1';
    int newCol = newPosition[0] - 'A';

    // Calculate the difference between current and new positions
    int rowDiff = abs(newRow - currentRow);
    int colDiff = abs(newCol - currentCol);

    // Check if the move is vertical, horizontal, or diagonal
    bool verticalMove = (currentCol == newCol && currentRow != newRow);
    bool horizontalMove = (currentRow == newRow && currentCol != newCol);
    bool diagonalMove = (rowDiff == colDiff);

    return verticalMove || horizontalMove || diagonalMove;
}