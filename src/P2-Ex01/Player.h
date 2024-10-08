#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include "pch.h"
#include "Board.h"  // Include the board for making moves

class Player {
private:
    string name;
    char color;
    bool isTurn;

public:
    // Constructor
    Player(string playerName, char pieceColor);

    // Getters
    string getName() const;
    char getColor() const;

    // Methods to manage turns
    void setTurn(bool turn);
    bool getTurn() const;

    // Method to make a move
    void makeMove(Board& board);
};

#endif
