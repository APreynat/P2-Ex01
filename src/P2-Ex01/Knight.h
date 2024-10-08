#include "pch.h"

class Knight : public ChessPiece {
public:
    Knight(char color, string position);

    // Override the isValidMove method
    bool isValidMove(string newPosition, ChessPiece* grid[8][8]) const override;
};