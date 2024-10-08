#include "pch.h"
#include "Pawn.h"

Pawn::Pawn(char color, string position) : ChessPiece (color, 'P', position) {}

#include <iostream>  // For debug output

bool Pawn::isValidMove(string newPosition, ChessPiece* grid[8][8]) const {

    // Extract current position row and column
    int currentRow = position[1] - '1';
    int currentCol = position[0] - 'A';

    // Extract new position row and column
    int newRow = newPosition[1] - '1';
    int newCol = newPosition[0] - 'A';

    // Calculate the difference between current and new positions
    int rowDiff = (newRow - currentRow);
    int colDiff = abs(newCol - currentCol);

    // Debug output to trace the move details
    std::cout << "Pawn moving from (" << currentRow << "," << currentCol << ") to ("
        << newRow << "," << newCol << ") with rowDiff: " << rowDiff << " and colDiff: " << colDiff << "\n";

    // Check for a one-cell forward move (rowDiff == 1) and column stays the same
    if (colDiff == 0) {
        // Single square move forward
        if (rowDiff == 1 && grid[newRow][newCol] == nullptr) {
            return true;  // Move one square forward is valid if the square is empty
        }

        // Two squares move forward (only from the starting row: index 6 for white pawns)
        if (rowDiff == 2 && currentRow == 6) {
            // Check if both the square in front and the target square are empty
            std::cout << "Checking two-square move...\n";
            if (grid[currentRow + 1][currentCol] == nullptr) {
                std::cout << "Square in front is empty.\n";
            }
            else {
                std::cout << "Square in front is NOT empty.\n";
            }

            if (grid[newRow][newCol] == nullptr) {
                std::cout << "Target square is empty.\n";
            }
            else {
                std::cout << "Target square is NOT empty.\n";
            }

            if (grid[currentRow + 1][currentCol] == nullptr && grid[newRow][newCol] == nullptr) {
                return true;  // Move two squares forward is valid if both squares are empty
            }
        }
    }

    return false;  // Invalid move
}
