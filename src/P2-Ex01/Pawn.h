#include "pch.h"

class Pawn : public ChessPiece {
public:
    Pawn(char color, string position);

    // Override the isValidMove method
    bool isValidMove(string newPosition) const override;

private:
    bool isFirstMove;
};