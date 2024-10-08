#include "pch.h"
#include "board.h"

Board::Board() {
    // Initialize the board with nullptr for empty squares
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            grid[i][j] = nullptr;
        }
    }
}

// Destructor to clean up allocated memory for chess pieces
Board::~Board() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (grid[i][j] != nullptr) {  // Check if the pointer is valid before deleting
                delete grid[i][j];        // Only delete if not nullptr
                grid[i][j] = nullptr;     // Set to nullptr after deletion
            }
        }
    }
}

// Place a chess piece at a specific position on the board
void Board::placePiece(ChessPiece* piece, string position) {
    int row, col;
    if (getPositionIndices(position, row, col)) {
        // Clean up any existing piece at this position
        if (grid[row][col] != nullptr) {
            delete grid[row][col];
        }
        grid[row][col] = piece;
        piece->move(position); // Update the piece's position
    }
    else {
        cout << "Invalid position: " << position << endl;
    }
}

bool Board::isPathClear(int fromRow, int fromCol, int toRow, int toCol) const {
    // Check if it's a horizontal move
    if (fromRow == toRow) {
        int step = (fromCol < toCol) ? 1 : -1;  // Move left or right
        for (int col = fromCol + step; col != toCol; col += step) {
            if (grid[fromRow][col] != nullptr) {
                return false;  // There's a piece in the way
            }
        }
    }
    // Check if it's a vertical move
    else if (fromCol == toCol) {
        int step = (fromRow < toRow) ? 1 : -1;  // Move up or down
        for (int row = fromRow + step; row != toRow; row += step) {
            if (grid[row][fromCol] != nullptr) {
                return false;  // There's a piece in the way
            }
        }
    }
    // For now, this function only supports straight-line (rook-like) movements
    // Additional checks for diagonal movement (bishop-like) can be added here

    return true;  // Path is clear
}

bool Board::movePiece(std::string fromPosition, std::string toPosition) {
    int fromRow, fromCol, toRow, toCol;

    // Get the indices for both the starting and destination positions
    if (getPositionIndices(fromPosition, fromRow, fromCol) && getPositionIndices(toPosition, toRow, toCol)) {
        ChessPiece* piece = grid[fromRow][fromCol];
        ChessPiece* destinationPiece = grid[toRow][toCol];  // Check the destination square

        // Check if there is a piece at the "from" position
        if (piece == nullptr) {
            std::cout << "No piece at " << fromPosition << std::endl;
            return false;
        }

        // Check if the destination is occupied by a piece of the same color
        if (destinationPiece != nullptr && destinationPiece->getColor() == piece->getColor()) {
            std::cout << "Cannot move to " << toPosition << ". A piece of the same color is already there." << std::endl;
            return false;  // Prevent further checks and return early
        }

        // Check if the move is valid for this piece, passing the grid for validation
        if (piece->isValidMove(toPosition, grid)) {
            delete grid[toRow][toCol];  // Remove any existing piece at the target (if it's an opponent's piece)
            grid[toRow][toCol] = piece;  // Place the piece at the new position
            grid[fromRow][fromCol] = nullptr;  // Set the old position to empty
            piece->move(toPosition);  // Update the piece's internal position
            return true;
        }
        else {
            std::cout << "Invalid move for " << piece->getSymbol() << std::endl;
            return false;
        }
    }
    else {
        std::cout << "Invalid position input." << std::endl;
        return false;
    }
}

// Convert the position string (e.g., "E2") to row and column indices
bool Board::getPositionIndices(string position, int& row, int& col) const {
    if (position.length() != 2) return false;

    // Convert column letter to index ('A' = 0, 'B' = 1, ..., 'H' = 7)
    col = position[0] - 'A';

    // Convert row number to index (row '1' = index 7, row '8' = index 0)
    row = 8 - (position[1] - '1' + 1);

    return (col >= 0 && col < 8 && row >= 0 && row < 8);
}

// Display the board
void Board::display() const {
    // Print the top row with A-H labels
    cout << "  A B C D E F G H" << endl;

    // Print each row with the corresponding row number and pieces
    for (int i = 0; i < 8; ++i) {
        cout << 8 - i << " ";  // Print the row number (1-8)
        for (int j = 0; j < 8; ++j) {
            if (grid[i][j] == nullptr) {
                cout << ". ";  // Print dot for empty squares
            }
            else {
                cout << grid[i][j]->getSymbol() << " ";  // Print the piece symbol
            }
        }
        cout << endl;  // New line after each row
    }
}