#include "pch.h"

class Rook : public ChessPiece {
public:
    Rook(char color, string position);

    // Override the isValidMove method
    bool isValidMove(string newPosition) const override;
};