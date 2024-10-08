#include "pch.h"
#include "Player.h"

// Constructor
Player::Player(string playerName, char pieceColor)
    : name(playerName), color(pieceColor), isTurn(false) {}

// Getter for the player name
string Player::getName() const {
    return name;
}

// Getter for the player color
char Player::getColor() const {
    return color;
}

// Set the player's turn status
void Player::setTurn(bool turn) {
    isTurn = turn;
}

// Check if it's the player's turn
bool Player::getTurn() const {
    return isTurn;
}

// Method for making a move on the board
void Player::makeMove(Board& board) {
    string fromPos, toPos;
    cout << name << "'s turn. Enter piece position to move: ";
    cin >> fromPos;
    cout << "Enter position to move to: ";
    cin >> toPos;
    board.movePiece(fromPos, toPos);  // Call the board's movePiece method
}
