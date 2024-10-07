#include "pch.h"
#include "Pawn.h"

Pawn::Pawn(char color, string position) : ChessPiece (color, 'P', position) {}

bool Pawn::isValidMove(string newPosition) const {

    // Extract current position row and column
    int currentRow = position[1] - '1';
    int currentCol = position[0] - 'A';

    // Extract new position row and column
    int newRow = newPosition[1] - '1';
    int newCol = newPosition[0] - 'A';

    // Calculate the difference between current and new positions
    int rowDiff = abs(newRow - currentRow);
    int colDiff = abs(newCol - currentCol);

    bool moveUp = (rowDiff == 1);

    return moveUp;

}