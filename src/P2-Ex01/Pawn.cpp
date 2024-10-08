#include "pch.h"
#include "Pawn.h"

// Helper function to convert position string (e.g., "E2") to row and column indices
bool getPositionIndices(string position, int& row, int& col) {
    if (position.length() != 2) return false;

    col = position[0] - 'A';
    row = 8 - (position[1] - '1' + 1);

    return (col >= 0 && col < 8 && row >= 0 && row < 8);
}

bool Pawn::isValidMove(string newPosition, ChessPiece* grid[8][8]) const {
    int fromRow, fromCol, toRow, toCol;

    // Use helper function to convert the positions
    getPositionIndices(position, fromRow, fromCol);
    getPositionIndices(newPosition, toRow, toCol);

    // Check the movement direction based on color
    int rowDirection = (color == 'W') ? -1 : 1;  // White moves up (-1), Black moves down (+1)

    // Standard pawn move: one step forward
    if (toCol == fromCol && toRow == fromRow + rowDirection && grid[toRow][toCol] == nullptr) {
        return true;
    }

    // First move: two steps forward
    if (toCol == fromCol && toRow == fromRow + 2 * rowDirection && getHasMoved()==false && grid[toRow][toCol] == nullptr && grid[fromRow + rowDirection][toCol] == nullptr) {
        return true;
    }

    // Capture: move diagonally to capture an opponent's piece
    if (abs(toCol - fromCol) == 1 && toRow == fromRow + rowDirection && grid[toRow][toCol] != nullptr && grid[toRow][toCol]->getColor() != color) {
        return true;
    }

    // Invalid move
    return false;
}


