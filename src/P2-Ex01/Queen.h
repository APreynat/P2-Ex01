#pragma once
#include "pch.h"

class Queen : public ChessPiece {
public:
    Queen(char color, string position);

    // Override the isValidMove method
    bool isValidMove(string newPosition, ChessPiece* grid[8][8]) const override;
};