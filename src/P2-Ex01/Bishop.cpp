#include "pch.h"
#include "Bishop.h"

Bishop::Bishop(char color, string position): ChessPiece(color, 'B', position) {}

bool Bishop::isValidMove(string newPosition) const {

    // Extract current position row and column
    int currentRow = position[1] - '1';
    int currentCol = position[0] - 'A';

    // Extract new position row and column
    int newRow = newPosition[1] - '1';
    int newCol = newPosition[0] - 'A';

    // Calculate the difference between current and new positions
    int rowDiff = std::abs(newRow - currentRow);
    int colDiff = std::abs(newCol - currentCol);

    // Check if the move is diagonal
    bool diagonalMove = (rowDiff == colDiff);  // Same magnitude of change in row and column

    return diagonalMove;
}