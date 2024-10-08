#pragma once
#include "pch.h"

class ChessPiece {

protected:
    char color; 
    char symbol;
    string position;
    bool hasMoved;

public:
    ChessPiece(char color, char symbol, string position);

    // Getters
    char getColor() const;
    char getSymbol() const;
    string getPosition() const;
    bool getHasMoved() const;

    // Virtual method to check if a move is valid
    virtual bool isValidMove(string newPosition, ChessPiece* grid[8][8]) const = 0;

    // Move the piece to a new position
    void move(string newPosition);

    // Virtual destructor
    virtual ~ChessPiece() {}
};
