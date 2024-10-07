#include "pch.h"

#include <iostream>
#include <vector>
#include <map>
#include <string>


class Board {
private:

public:

    vector<vector<ChessPiece*>> grid;

    // Constructor: initialize an empty 8x8 board
    Board();

    // Destructor to clean up dynamically allocated chess pieces
    ~Board();

    // Add a piece to the board at a specific position
    void placePiece(ChessPiece* piece, string position);

    // Move a piece from one position to another if valid
    bool movePiece(string fromPosition, string toPosition);

    // Display the current state of the board
    void display() const;

    // Convert the position string (e.g., "E2") into row and column indices
    bool getPositionIndices(string position, int& row, int& col) const;
};
