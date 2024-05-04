#include <stdio.h>

char board[3][3]; // 3x3 Tic Tac Toe board

// Initialize the board
void init_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Display the board
void display_board() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Check if a player has won
int check_win(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1; // Row
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1; // Column
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1; // Diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1; // Diagonal
    return 0;
}

// Check if the board is full
int check_full() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0; // Not full
        }
    }
    return 1; // Full
}

int main() {
    int row, col;
    char player = 'X'; // Player X starts first

    init_board();

    while (1) {
        display_board();

        // Input row and column from the current player
        printf("\nPlayer %c's turn (row[1-3] column[1-3]): ", player);
        scanf("%d %d", &row, &col);

        // Convert to 0-based indexing
        row--;
        col--;

        // Check if the input is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Set the move on the board
        board[row][col] = player;

        // Check for a win
        if (check_win(player)) {
            display_board();
            printf("\nPlayer %c wins!\n", player);
            break;
        }

        // Check for a draw
        if (check_full()) {
            display_board();
            printf("\nIt's a draw!\n");
            break;
        }

        // Switch players
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}