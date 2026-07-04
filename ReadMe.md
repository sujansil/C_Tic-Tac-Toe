# Tic-Tac-Toe in C
	A simple, two player console-based implementation of the classic Tic-Tac-Toe game.
## Features
1. **Grid Display** : Real-time board updates after every turn.
2. **Input Validation** : Prevents players from entering invalid numbers or selcting occupied boxes.
3. **Win/Draw Detection** : Automaticallly checks for rows, coloumns, and diagonal wins, or notifies of a draw after 9 turns.

## Game Rules 
1. The board is represented by number 1 through 9.
2. Player 1 plays as **X** and Player 2 plays as **O**.
3. Player take turns entering the number of the box they want to claim.
4. The game automatically checks for a winner after every move or declares draw if the board fills up.

## Project Structure
1. `printBoard()` : Handles the UI and board visualization in the cosole.
2. `checkWinner()` : Contains the logic to evaluate rows, coloums, and diagonals for a win.
3. `repetation() : Manage input validation, ensuring players don't enter invalid numbers or choose a squre that already is taken.
4. `main()` : Coordinates the game loop and alternates between players.

