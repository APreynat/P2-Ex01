#pragma once
#include "pch.h"


#ifndef PAWN_H
#define PAWN_H

class Pawn : public ChessPiece {
public:
    Pawn(char color, string position) : ChessPiece(color, 'P', position) {}

    bool isValidMove(string newPosition, ChessPiece* grid[8][8]) const override;
};

#endif
