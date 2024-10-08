#pragma once
#include "pch.h"

class Bishop : public ChessPiece {
public:
    Bishop(char color, string position);

    // Override the isValidMove method
    bool isValidMove(string newPosition, ChessPiece* grid[8][8]) const override;
};