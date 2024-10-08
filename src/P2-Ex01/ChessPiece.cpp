#include "pch.h"

// Constructor implementation
ChessPiece::ChessPiece(char color, char symbol, string position)
    : color(color), symbol(symbol), position(position), hasMoved(false) {}

// Getter for symbol
char ChessPiece::getSymbol() const {
    return symbol;
}

// Getter for color
char ChessPiece::getColor() const {
    return color;
}

// Getter for position
string ChessPiece::getPosition() const {
    return position;
}

// Getter for hasMoved
bool ChessPiece::getHasMoved() const {
    return hasMoved;
}

// Move method implementation
void ChessPiece::move(string newPosition) {
    position = newPosition;
    hasMoved = true;
}