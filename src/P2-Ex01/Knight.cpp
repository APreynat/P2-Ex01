#include "pch.h"
#include "Knight.h"

Knight::Knight(char color, string position): ChessPiece(color, 'L', position) {}

bool Knight::isValidMove(string newPosition) const {

    // Extract current position row and column
    int currentRow = position[1] - '1';
    int currentCol = position[0] - 'A';

    // Extract new position row and column
    int newRow = newPosition[1] - '1';
    int newCol = newPosition[0] - 'A';

    // Calculate the difference between current and new positions
    int rowDiff = abs(newRow - currentRow);
    int colDiff = abs(newCol - currentCol);

    // Knight moves in an L-shape
    return (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);
}