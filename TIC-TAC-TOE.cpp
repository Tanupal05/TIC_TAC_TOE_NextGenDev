#include <iostream>
#include <vector>
#include <string>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';
bool gameEnd = false;
string n1 = "";
string n2 = "";

// Function to display the game board
void displayBoard()
{
  cout << "-------------" << endl;
  for (int i = 0; i < 3; ++i)
  {
    cout << "| ";
    for (int j = 0; j < 3; ++j)
    {
      cout << board[i][j] << " | ";
    }
    cout << endl;
    cout << "-------------" << endl;
  }
}

// Function to check if the current player has won
bool checkWin()
{
  // Check rows and columns
  for (int i = 0; i < 3; ++i)
  {
    if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
    {
      return true; // Row i
    }
    if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
    {
      return true; // Column i
    }
  }
  // Check diagonals
  if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
  {
    return true; // Main diagonal
  }
  if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
  {
    return true; // Anti-diagonal
  }
  return false;
}

// Function to check if the board is full (draw)
bool checkDraw()
{
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      if (board[i][j] != 'X' && board[i][j] != 'O')
      {
        return false; // Empty space found
      }
    }
  }
  return true; // Board is full
}

// Function to switch players
void switchPlayers()
{
  currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to play the game
void playGame()
{
  int row, col;
  while (!gameEnd)
  {
    displayBoard();

    // Get player's move
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    int move;
    cin >> move;

    // Convert move to board indices
    row = (move - 1) / 3;
    col = (move - 1) % 3;

    // Validate move
    if (move < 1 || move > 9 || board[row][col] == 'X' || board[row][col] == 'O')
    {
      cout << "Invalid move! Try again." << endl;
      continue;
    }

    // Update board with player's move
    board[row][col] = currentPlayer;

    // Check for win
    if (checkWin())
    {
      displayBoard();
      cout << "Player " << currentPlayer << " wins!" << endl;
      gameEnd = true;
    }
    else if (checkDraw())
    {
      displayBoard();
      cout << "It's a draw!" << endl;
      gameEnd = true;
    }
    else
    {
      // Switch players for the next turn
      switchPlayers();
    }
  }
}

int main()
{
  char playAgain;
  do
  {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Enter the name of the First player: \n";
    getline(cin, n1);
    cout << "Enter the name of the second player: \n";
    getline(cin, n2);
    cout << n1 << " Player 1: X \n";
    cout << n2 << " Player 2: O \n";
    cout << "The board is numbered from 1 to 9 (left to right, top to bottom)." << endl;
    cout << "Players take turns entering their moves." << endl;

    // Initialize the board
    for (int i = 0; i < 3; ++i)
    {
      for (int j = 0; j < 3; ++j)
      {
        board[i][j] = '1' + i * 3 + j;
      }
    }

    // Start the game
    playGame();

    // Ask if players want to play again
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    // Reset variables for a new game
    currentPlayer = 'X';
    gameEnd = false;

  } while (playAgain == 'y' || playAgain == 'Y');

  cout << "Thanks for playing Tic-Tac-Toe!" << endl;

  return 0;
}
