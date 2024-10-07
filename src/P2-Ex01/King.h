#include "pch.h"

class King : public ChessPiece {
public:
    King(char color, string position);

    // Override the isValidMove method
    bool isValidMove(string newPosition) const override;
};