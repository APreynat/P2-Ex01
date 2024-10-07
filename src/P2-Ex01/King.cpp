#include "pch.h"
#include "King.h"

King::King(char color, string position) : ChessPiece(color, 'K', position) {}

bool King::isValidMove(std::string newPosition) const {
    int currentRow = position[1] - '1';
    int currentCol = position[0] - 'A';

    int newRow = newPosition[1] - '1';
    int newCol = newPosition[0] - 'A';

    // King moves one square in any direction
    return (abs(newRow - currentRow) <= 1 && abs(newCol - currentCol) <= 1);
}